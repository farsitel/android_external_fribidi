/* FriBidi
 * fribidi-bidi-type.c - get character bidi type
 *
 * $Id: fribidi-bidi-type.c,v 1.13 2004-06-14 17:00:33 behdad Exp $
 * $Author: behdad $
 * $Date: 2004-06-14 17:00:33 $
 * $Revision: 1.13 $
 * $Source: /cvs/fribidi/fribidi2/lib/Attic/fribidi-bidi-type.c,v $
 *
 * Authors:
 *   Behdad Esfahbod, 2001, 2002, 2004
 *
 * Copyright (C) 2004 Sharif FarsiWeb, Inc
 * Copyright (C) 2001,2002 Behdad Esfahbod
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

#include "common.h"

#include <fribidi-bidi-type.h>

enum FriBidiCharTypeLinearEnum
{
# define _FRIBIDI_ADD_TYPE(TYPE,SYMBOL) TYPE,
# include "fribidi-bidi-types-list.h"
# undef _FRIBIDI_ADD_TYPE
  _FRIBIDI_NUM_TYPES
};

#include "bidi-type.tab.i"

/* Map FriBidiCharTypeLinearEnum to FriBidiCharType. */
static const FriBidiCharType linear_enum_to_char_type[] = {
# define _FRIBIDI_ADD_TYPE(TYPE,SYMBOL) FRIBIDI_TYPE_##TYPE,
# include "fribidi-bidi-types-list.h"
# undef _FRIBIDI_ADD_TYPE
};

FRIBIDI_ENTRY FriBidiCharType
fribidi_get_bidi_type (
  /* input */
  FriBidiChar ch
)
{
  return linear_enum_to_char_type[FRIBIDI_GET_BIDI_TYPE (ch)];
}

FRIBIDI_ENTRY void
fribidi_get_bidi_types (
  /* input */
  const FriBidiChar *str,
  FriBidiStrIndex len,
  /* output */
  FriBidiCharType *type
)
{
  register FriBidiStrIndex i = len;
  for (; i; i--)
    *type++ = fribidi_get_bidi_type (*str++);
}

/* Editor directions:
 * vim:textwidth=78:tabstop=8:shiftwidth=2:autoindent:cindent
 */
