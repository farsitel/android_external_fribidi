/* FriBidi
 * fribidi-unicode.h - general Unicode definitions
 *
 * $Id: fribidi-unicode.h,v 1.1 2004-04-25 18:47:57 behdad Exp $
 * $Author: behdad $
 * $Date: 2004-04-25 18:47:57 $
 * $Revision: 1.1 $
 * $Source: /cvs/fribidi/fribidi2/lib/fribidi-unicode.h,v $
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
#ifndef _FRIBIDI_UNICODE_H
#define _FRIBIDI_UNICODE_H

#include "fribidi-common.h"

#include "fribidi-types.h"

#include "fribidi-begindecls.h"

/* We do not support surrogates yet */
#define FRIBIDI_UNICODE_CHARS	(sizeof(FriBidiChar) >= 4 ? 0x110000 : 0xFFFE)
/* Unicode version - FRIBIDI_UNICODE_VERSION */
#if !DONT_HAVE_FRIBIDI_UNICODE_VERSION_H
# include "fribidi-unicode-version.h"
#else /* DONT_HAVE_FRIBIDI_UNICODE_VERSION_H */
# define FRIBIDI_UNICODE_VERSION "unknown"
#endif /* DONT_HAVE_FRIBIDI_UNICODE_VERSION_H */

/* The maximum embedding level value assigned by explicit marks */
#define FRIBIDI_BIDI_MAX_EXPLICIT_LEVEL		61
/* The maximum *number* of different resolved embedding levels: 0-62 */
#define FRIBIDI_BIDI_MAX_RESOLVED_LEVELS	63

/* Bidirectional marks */
#define FRIBIDI_CHAR_LRM		0x200E
#define FRIBIDI_CHAR_RLM		0x200F
#define FRIBIDI_CHAR_LRE		0x202A
#define FRIBIDI_CHAR_RLE		0x202B
#define FRIBIDI_CHAR_PDF		0x202C
#define FRIBIDI_CHAR_LRO		0x202D
#define FRIBIDI_CHAR_RLO		0x202E

/* Line and Paragraph Separators */
#define FRIBIDI_CHAR_LS			0x2028
#define FRIBIDI_CHAR_PS			0x2029

/* Arabic Joining marks */
#define FRIBIDI_CHAR_ZWNJ		0x200C
#define FRIBIDI_CHAR_ZWJ		0x200D

/* Hebrew and Arabic */
#define FRIBIDI_CHAR_HEBREW_ALEF	0x05D0
#define FRIBIDI_CHAR_ARABIC_ALEF	0x0627
#define FRIBIDI_CHAR_ARABIC_ZERO	0x0660
#define FRIBIDI_CHAR_PERSIAN_ZERO	0x06F0

/* These are here just for compatibility. */
#define UNI_MAX_BIDI_LEVEL	FRIBIDI_BIDI_MAX_EXPLICIT_LEVEL
#define UNI_LRM			FRIBIDI_CHAR_LRM
#define UNI_RLM			FRIBIDI_CHAR_RLM
#define UNI_LRE			FRIBIDI_CHAR_LRE
#define UNI_RLE			FRIBIDI_CHAR_RLE
#define UNI_LRO			FRIBIDI_CHAR_LRO
#define UNI_RLO			FRIBIDI_CHAR_RLO
#define UNI_LS			FRIBIDI_CHAR_LS
#define UNI_PS			FRIBIDI_CHAR_PS
#define UNI_ZWNJ		FRIBIDI_CHAR_ZWNJ
#define UNI_ZWJ			FRIBIDI_CHAR_ZWJ
#define UNI_HEBREW_ALEF		FRIBIDI_CHAR_HEBREW_ALEF
#define UNI_ARABIC_ALEF		FRIBIDI_CHAR_ARABIC_ALEF
#define UNI_ARABIC_ZERO		FRIBIDI_CHAR_ARABIC_ZERO
#define UNI_FARSI_ZERO		FRIBIDI_CHAR_PERSIAN_ZERO

#include "fribidi-enddecls.h"

#endif /* !_FRIBIDI_UNICODE_H */
/* Editor directions:
 * vim:textwidth=78:tabstop=8:shiftwidth=2:autoindent:cindent
 */
