#if !__C2MAN__
/* FriBidi
 * bidi-types-list.h - list of bidi types
 *
 * $Id: bidi-types-list.h,v 1.1 2004-04-25 18:47:57 behdad Exp $
 * $Author: behdad $
 * $Date: 2004-04-25 18:47:57 $
 * $Revision: 1.1 $
 * $Source: /cvs/fribidi/fribidi2/lib/Attic/bidi-types-list.h,v $
 *
 * Author:
 *   Behdad Esfahbod, 2001, 2002, 2004
 *
 * Copyright (C) 2004 Sharif FarsiWeb, Inc.
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
/* *INDENT-OFF* */
#endif /* !__C2MAN__ */

/* Bidi types from the standard. */
_FRIBIDI_ADD_TYPE (LTR, 'L')	/* Left-To-Right letter */
_FRIBIDI_ADD_TYPE (RTL, 'R')	/* Right-To-Left letter */
_FRIBIDI_ADD_TYPE (AL, 'A')	/* Arabic Letter */
_FRIBIDI_ADD_TYPE (EN, '1')	/* European Numeral */
_FRIBIDI_ADD_TYPE (AN, '9')	/* Arabic Numeral */
_FRIBIDI_ADD_TYPE (ES, 'w')	/* European number Separator */
_FRIBIDI_ADD_TYPE (ET, 'w')	/* European number Terminator */
_FRIBIDI_ADD_TYPE (CS, 'w')	/* Common Separator */
_FRIBIDI_ADD_TYPE (NSM, '`')	/* Non Spacing Mark */
_FRIBIDI_ADD_TYPE (BN, 'b')	/* Boundary Neutral */
_FRIBIDI_ADD_TYPE (BS, 'B')	/* Block Separator */
_FRIBIDI_ADD_TYPE (SS, 'S')	/* Segment Separator */
_FRIBIDI_ADD_TYPE (WS, '_')	/* White-Space */
_FRIBIDI_ADD_TYPE (ON, 'n')	/* Other Neutral */
_FRIBIDI_ADD_TYPE (LRE, '+')	/* Left-to-Right Embedding */
_FRIBIDI_ADD_TYPE (RLE, '+')	/* Right-to-Left Embedding */
_FRIBIDI_ADD_TYPE (LRO, '+')	/* Left-to-Right Override */
_FRIBIDI_ADD_TYPE (RLO, '+')	/* Right-to-Left Override */
_FRIBIDI_ADD_TYPE (PDF, '-')	/* Pop Directional Flag */

/* The following two types are not official Unicode bidi types, but used for
 * paragraph direction handling only. */
_FRIBIDI_ADD_TYPE (WL, 'l')	/* Weak Left to right */
_FRIBIDI_ADD_TYPE (WR, 'r')	/* Weak Right to left */

/* The following two types are used internally only. */
_FRIBIDI_ADD_TYPE (SOT, '^')	/* Start Of Text */
_FRIBIDI_ADD_TYPE (EOT, '$')	/* End Of Text */

#if !__C2MAN__
/* *INDENT-ON* */
#endif /* !__C2MAN__ */
