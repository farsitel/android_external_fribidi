/* FriBidi
 * fribidi-bidi-type.h - get character bidi type
 *
 * $Id: fribidi-bidi-type.h,v 1.5 2004-06-09 14:59:21 behdad Exp $
 * $Author: behdad $
 * $Date: 2004-06-09 14:59:21 $
 * $Revision: 1.5 $
 * $Source: /cvs/fribidi/fribidi2/lib/Attic/fribidi-bidi-type.h,v $
 *
 * Author:
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
#ifndef _FRIBIDI_BIDI_TYPE_H
#define _FRIBIDI_BIDI_TYPE_H

#include "fribidi-common.h"

#include "fribidi-types.h"
#include "fribidi-bidi-types.h"

#include "fribidi-begindecls.h"

#define fribidi_get_bidi_type FRIBIDI_NAMESPACE(get_bidi_type)
/* fribidi_get_bidi_type - get character bidi type
 *
 * This function returns the bidi type of a character.  There are a few macros
 * defined in fribidi-bidi-types.h for querying a bidi type.
 */
FRIBIDI_ENTRY FriBidiCharType
fribidi_get_bidi_type (
  FriBidiChar ch		/* input character */
) FRIBIDI_GNUC_CONST;

#include "fribidi-enddecls.h"

#endif /* !_FRIBIDI_BIDI_TYPE_H */
/* Editor directions:
 * vim:textwidth=78:tabstop=8:shiftwidth=2:autoindent:cindent
 */
