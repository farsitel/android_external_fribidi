/* FriBidi
 * gen-mirroring-tab.c - generate mirroring.tab.i for libfribidi
 *
 * $Id: gen-mirroring-tab.c,v 1.2 2004-05-12 07:06:21 behdad Exp $
 * $Author: behdad $
 * $Date: 2004-05-12 07:06:21 $
 * $Revision: 1.2 $
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

#define appname "gen-mirroring-tab"
#define outputname "mirroring.tab.i"

static void
die (
  char *msg
)
{
  fprintf (stderr, appname ": %s\n", msg);
  exit (1);
}

static void
die2 (
  char *fmt,
  char *p
)
{
  fprintf (stderr, appname ": ");
  fprintf (stderr, fmt, p);
  fprintf (stderr, "\n");
  exit (1);
}

static FriBidiChar table[FRIBIDI_UNICODE_CHARS];

static int mirroring_count;

static void
init_tab()
{
  register FriBidiChar i;

  for (i = 0; i < FRIBIDI_UNICODE_CHARS; i++)
    table[i] = 0;
  mirroring_count = 0;
}

static void
read_bidi_mirroring_txt (
  FILE *f
)
{
  char s[200];

  while (fgets (s, sizeof s, f))
    {
      unsigned long i, j;

      if (s[0] == '#' || s[0] == '\0' || s[0] == '\n')
	continue;
      sscanf (s, "%lx; %lx", &i, &j);
      if (i >= FRIBIDI_UNICODE_CHARS || j >= FRIBIDI_UNICODE_CHARS)
      {
	fprintf(stderr, "ignoring invalid pair %04lX, %04lX\n", i, j);
	continue;
      }
      table[i] = j;
      mirroring_count++;
    }
}

static void read_data (
  char *data_file_type,
  char *data_file_name
)
{
  FILE *f;

  fprintf (stderr, "Reading `%s'\n", data_file_name);
  if (!(f = fopen (data_file_name, "rt")))
    die2 ("error: cannot open `%s' for reading", data_file_name);

  if (!strcmp(data_file_type, "BidiMirroring.txt"))
    read_bidi_mirroring_txt(f);
  else
    die2 ("error: unknown data-file-type %s", data_file_type);

  fclose(f);
}

static void
gen_mirroring_tab (
  char *data_file_type
)
{
  FriBidiChar i;

  fprintf (stderr, "Generating output, it may take up to a few seconds\n");
  printf ("/* " outputname " generated by " appname " (" FRIBIDI_NAME FRIBIDI_VERSION ")\n"
	  " * from the file %s of Unicode version " FRIBIDI_UNICODE_VERSION ". */\n\n", data_file_type);

  printf ("/* *IND" "ENT-OFF" "* */\n\n");
  printf ("static const struct _FriBidiMirroredPair FriBidiMirroredChars[] =\n{\n");
  for (i = 0; i < FRIBIDI_UNICODE_CHARS; i++)
    if (table[i])
      printf ("  {0x%04lX, 0x%04lX},\n", (unsigned long) i, (unsigned long) table[i]);
  printf ("} ;\n\n");
  printf ("/* *IND" "ENT-ON* */\n\n");
  printf ("static const int nFriBidiMirroredChars = %d;\n\n", mirroring_count);

  printf ("/* End of generated " outputname " */\n");
}

int
main (
  int argc,
  char **argv
)
{
  if (argc != 3)
    die ("usage:\n  " appname " data-file-type data-file-name\n"
	 "where data-file-type is:\n"
	 "  * BidiMirroring.txt");
  {
  char *data_file_type = argv[1];
  char *data_file_name = argv[2];

  init_tab ();
  read_data (data_file_type, data_file_name);
  gen_mirroring_tab (data_file_type);
  }

  return 0;
}
