/* FriBidi
 * gen-mirroring-tab.c - generate bidi-mirroring.i for libfribidi
 *
 * $Id: gen-mirroring-tab.c,v 1.9 2004-06-13 20:11:42 behdad Exp $
 * $Author: behdad $
 * $Date: 2004-06-13 20:11:42 $
 * $Revision: 1.9 $
 * $Source: /cvs/fribidi/fribidi2/gen.tab/gen-mirroring-tab.c,v $
 *
 * Author:
 *   Behdad Esfahbod, 2001, 2002, 2004
 *
 * Copyright (C) 2004 Sharif FarsiWeb, Inc
 * Copyright (C) 2001,2002,2004 Behdad Esfahbod
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library, in a file named COPYING; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307, USA
 * 
 * For licensing issues, contact <license@farsiweb.info>.
 */

#include <common.h>

#include <fribidi-unicode.h>

#include <stdio.h>
#if STDC_HEADERS
# include <stdlib.h>
# include <stddef.h>
#else
# if HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif
#if HAVE_STRINGS_H
# include <strings.h>
#endif

#include "packtab.h"

#define appname "gen-mirroring-tab"
#define outputname "mirroring.tab.i"

static void
die (
  const char *msg
)
{
  fprintf (stderr, appname ": %s\n", msg);
  exit (1);
}

static void
die2 (
  const char *fmt,
  const char *p
)
{
  fprintf (stderr, appname ": ");
  fprintf (stderr, fmt, p);
  fprintf (stderr, "\n");
  exit (1);
}

static void
die4 (
  const char *fmt,
  unsigned long l,
  unsigned long p,
  unsigned long q
)
{
  fprintf (stderr, appname ": ");
  fprintf (stderr, fmt, l, p, q);
  fprintf (stderr, "\n");
  exit (1);
}

#define table_name "Mir"
#define macro_name "FRIBIDI_GET_MIRRORING"

static signed int table[FRIBIDI_UNICODE_CHARS];
static char buf[4000];
static signed long max_dist;

static void
init (
)
{
  max_dist = 0;
}

static void
clear_tab (
)
{
  register FriBidiChar c;

  for (c = 0; c < FRIBIDI_UNICODE_CHARS; c++)
    table[c] = 0;
}

static void
init_tab_mirroring_txt (
)
{
  clear_tab ();
}

static void
read_bidi_mirroring_txt (
  FILE *f
)
{
  unsigned long l;

  init_tab_mirroring_txt ();

  l = 0;
  while (fgets (buf, sizeof buf, f))
    {
      unsigned long i, j;
      signed long dist;
      int k;
      const char *s = buf;

      l++;

      while (*s == ' ')
	s++;

      if (s[0] == '#' || s[0] == '\0' || s[0] == '\n')
	continue;

      k = sscanf (s, "%lx; %lx", &i, &j);
      if (k != 2 || i < 0 || i >= FRIBIDI_UNICODE_CHARS || j < 0
	  || j >= FRIBIDI_UNICODE_CHARS)
	die4 ("invalid pair in input at line %ld: %04lX, %04lX", l, i, j);
      dist = ((signed long) j - (signed long) i);
      table[i] = dist;
      if (dist > max_dist)
	max_dist = dist;
      else if (-dist > max_dist)
	max_dist = -dist;
    }
}

static void
read_data (
  const char *data_file_type,
  const char *data_file_name
)
{
  FILE *f;

  fprintf (stderr, "Reading `%s'\n", data_file_name);
  if (!(f = fopen (data_file_name, "rt")))
    die2 ("error: cannot open `%s' for reading", data_file_name);

  if (!strcmp (data_file_type, "BidiMirroring.txt"))
    read_bidi_mirroring_txt (f);
  else
    die2 ("error: unknown data-file-type %s", data_file_type);

  fclose (f);
}

static void
gen_mirroring_tab (
  int max_depth,
  const char *data_file_type
)
{
  int key_bytes;
  const char *key_type;

  fprintf (stderr, "Generating output, it may take up to a few minutes\n");
  printf ("/* " outputname "\n * generated by " appname " (" FRIBIDI_NAME " "
	  FRIBIDI_VERSION ")\n" " * from the file %s of Unicode version "
	  FRIBIDI_UNICODE_VERSION ". */\n\n", data_file_type);

  printf ("#define PACKTAB_UINT8 fribidi_uint8\n"
	  "#define PACKTAB_UINT16 fribidi_uint16\n"
	  "#define PACKTAB_UINT32 fribidi_uint32\n\n");

  key_bytes = max_dist <= 0x7f ? 1 : max_dist < 0x7fff ? 2 : 4;
  key_type = key_bytes == 1 ? "fribidi_int8" : key_bytes == 2 ?
    "fribidi_int16" : "fribidi_int32";

  if (!pack_table
      (table, FRIBIDI_UNICODE_CHARS, key_bytes, 0, max_depth, 1, NULL,
       key_type, table_name, macro_name "_DELTA", stdout))
    die ("error: insufficient memory, decrease max_depth");

  printf ("#undef PACKTAB_UINT8\n"
	  "#undef PACKTAB_UINT16\n" "#undef PACKTAB_UINT32\n\n");

  printf ("#define " macro_name "(x) ((x) + " macro_name "_DELTA(x))\n\n");

  printf ("/* End of generated " outputname " */\n");
}

int
main (
  int argc,
  const char **argv
)
{
  const char *data_file_type = "BidiMirroring.txt";
  if (argc < 3)
    die2 ("usage:\n  " appname " max-depth /path/to/%s [junk...]",
	  data_file_type);
  {
    int max_depth = atoi (argv[1]);
    const char *data_file_name = argv[2];

    if (max_depth < 2)
      die ("invalid depth");

    init ();
    read_data (data_file_type, data_file_name);
    gen_mirroring_tab (max_depth, data_file_type);
  }

  return 0;
}
