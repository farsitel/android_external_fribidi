/* FriBidi
 * debug.h - debug-only interfaces
 *
 * $Id: debug.h,v 1.3 2004-05-03 22:05:19 behdad Exp $
 * $Author: behdad $
 * $Date: 2004-05-03 22:05:19 $
 * $Revision: 1.3 $
 * $Source: /cvs/fribidi/fribidi2/lib/debug.h,v $
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
#ifndef _DEBUG_H
#define _DEBUG_H

#include "common.h"

#include <fribidi-types.h>

#include <fribidi-begindecls.h>

#if DEBUG

/* These definitions should only be used in DEBUG mode: */
#if HAVE_STRINGIZE
# define STRINGIZE(symbol) #symbol
#else /* !HAVE_STRINGIZE */
# define STRINGIZE(symbol)
#endif /* !HAVE_STRINGIZE */
#ifndef __LINE__
# define __LINE__ 0
#endif /* !__LINE__ */
#ifndef __FILE__
# define __FILE__ "unknown"
#endif /* !__FILE__ */

#ifndef FRIBIDI_FPRINTF
# ifndef __C2MAN__
#  include <stdio.h>
# endif	/* !__C2MAN__ */
# define FRIBIDI_FPRINTF fprintf
# define FRIBIDI_STDERR_ stderr,
#endif /* !FRIBIDI_FPRINTF */

#ifndef MSG
#define MSG(s) \
	FRIBIDI_BEGIN_STMT \
	FRIBIDI_FPRINTF(FRIBIDI_STDERR_ s); \
	FRIBIDI_END_STMT
#define MSG2(s, t) \
	FRIBIDI_BEGIN_STMT \
	FRIBIDI_FPRINTF(FRIBIDI_STDERR_ s, t); \
	FRIBIDI_END_STMT
#define MSG5(s, t, u, v, w) \
	FRIBIDI_BEGIN_STMT \
	FRIBIDI_FPRINTF(FRIBIDI_STDERR_ s, t, u, v, w); \
	FRIBIDI_END_STMT
#endif /* !MSG */

#ifndef DBG
# define DBG(s) \
	FRIBIDI_BEGIN_STMT \
	if (fribidi_debug_status()) MSG(FRIBIDI ": " s "\n"); \
	FRIBIDI_END_STMT
# define DBG2(s, t) \
	FRIBIDI_BEGIN_STMT \
	if (fribidi_debug_status()) MSG2(FRIBIDI ": " s "\n", t); \
	FRIBIDI_END_STMT
#endif /* !DBG */

#ifndef fribidi_assert
# define fribidi_assert(cond) \
	FRIBIDI_BEGIN_STMT \
	if (!(cond)) \
		DBG("file " __FILE__ ": line " STRINGIZE(__LINE__) ": " \
		    "assertion failed (" STRINGIZE(cond) ")"); \
	FRIBIDI_END_STMT
#endif /* !fribidi_assert */

#else /* !DEBUG */

#ifndef DBG
# define DBG(s)			FRIBIDI_EMPTY_STMT
# define DBG2(s, t)		FRIBIDI_EMPTY_STMT
#endif /* !DBG */
#ifndef fribidi_assert
# define fribidi_assert(cond)	FRIBIDI_EMPTY_STMT
#endif /* !fribidi_assert */

#endif /* !DEBUG */

#include <fribidi-enddecls.h>

#endif /* !_DEBUG_H */
/* Editor directions:
 * vim:textwidth=78:tabstop=8:shiftwidth=2:autoindent:cindent
 */
