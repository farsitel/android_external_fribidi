/* fribidi-mirroring.c - get mirrored character
 *
 * Copyright (C) 2004  Sharif FarsiWeb, Inc
 * Copyright (C) 2001, 2002, 2004  Behdad Esfahbod
 * Copyright (C) 1999, 2000  Dov Grobgeld
 *
 * This file is part of GNU FriBidi.
 * 
 * GNU FriBidi is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 * 
 * GNU FriBidi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with GNU FriBidi; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * 
 * For licensing issues, contact <license@farsiweb.info> or write to
 * Sharif FarsiWeb, Inc., PO Box 13445-389, Tehran, Iran.
 */
/* $Id: fribidi-mirroring.c,v 1.13 2004-06-15 11:52:02 behdad Exp $
 * $Author: behdad $
 * $Date: 2004-06-15 11:52:02 $
 * $Revision: 1.13 $
 * $Source: /cvs/fribidi/fribidi2/lib/fribidi-mirroring.c,v $
 *
 * Authors:
 *   Behdad Esfahbod, 2001, 2002, 2004
 *   Dov Grobgeld, 1999, 2000
 */

#include "common.h"

#include <fribidi-mirroring.h>

#include "mirroring.tab.i"

FRIBIDI_ENTRY fribidi_boolean
fribidi_get_mirror_char (
  /* input */
  FriBidiChar ch,
  /* output */
  FriBidiChar *mirrored_ch
)
{
  register FriBidiChar result;
  result = FRIBIDI_GET_MIRRORING (ch);
  if (mirrored_ch)
    *mirrored_ch = result;
  return ch != result ? true : false;
}


FRIBIDI_ENTRY void
fribidi_shape_mirroring (
  /* input */
  const FriBidiLevel *embedding_levels,
  const FriBidiStrIndex len,
  /* input and output */
  FriBidiChar *str
)
{
  register FriBidiStrIndex i;

  DBG ("in fribidi_shape_mirroring");

  fribidi_assert (embedding_levels);

  if UNLIKELY
    (len == 0 || !str) return;

  /* L4. Mirror all characters that are in odd levels and have mirrors. */
  for (i = len - 1; i >= 0; i--)
    if (FRIBIDI_LEVEL_IS_RTL (embedding_levels[i]))
      {
	FriBidiChar mirrored_ch;

	if (fribidi_get_mirror_char (str[i], &mirrored_ch))
	  str[i] = mirrored_ch;
      }
}

/* Editor directions:
 * Local Variables:
 *   mode: c
 *   c-basic-offset: 2
 *   indent-tabs-mode: t
 *   tab-width: 8
 * End:
 * vim: textwidth=78: autoindent: cindent: shiftwidth=2: tabstop=8:
 */
