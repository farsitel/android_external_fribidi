/* FriBidi
 * mem.h - memory manipulation routines
 *
 * $Id: mem.h,v 1.2 2004-04-27 16:47:22 behdad Exp $
 * $Author: behdad $
 * $Date: 2004-04-27 16:47:22 $
 * $Revision: 1.2 $
 * $Source: /cvs/fribidi/fribidi2/lib/mem.h,v $
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
#ifndef _MEM_H
#define _MEM_H

#include <fribidi-common.h>

#include <fribidi-types.h>

#include "common.h"

#include <fribidi-begindecls.h>

#if !FRIBIDI_USE_GLIB

typedef struct _FriBidiMemChunk FriBidiMemChunk;

#define FRIBIDI_ALLOC_ONLY      1

#define fribidi_mem_chunk_new FRIBIDI_NAMESPACE(mem_chunk_new)
FriBidiMemChunk *fribidi_mem_chunk_new (
  const char *name,
  int atom_size,
  unsigned long area_size,
  int alloc_type
);

#define fribidi_mem_chunk_alloc FRIBIDI_NAMESPACE(mem_chunk_alloc)
void *fribidi_mem_chunk_alloc (
  FriBidiMemChunk *mem_chunk
);

#else /* FRIBIDI_USE_GLIB */

#ifndef __C2MAN__
# include <glib/gmem.h>
#endif /* !__C2MAN__ */

#define FriBidiMemChunk GMemChunk
#define FRIBIDI_ALLOC_ONLY G_ALLOC_ONLY
#define fribidi_mem_chunk_new g_mem_chunk_new
#define fribidi_mem_chunk_alloc g_mem_chunk_alloc

#endif /* FRIBIDI_USE_GLIB */

#define fribidi_chunk_new(type, chunk)        ( \
		(type *) fribidi_mem_chunk_alloc (chunk) \
	)

#define fribidi_chunk_new_for_type(type) ( \
		fribidi_mem_chunk_new(FRIBIDI, sizeof (type), \
				FRIBIDI_CHUNK_SIZE, FRIBIDI_ALLOC_ONLY) \
	)

#include <fribidi-enddecls.h>

#endif /* !_MEM_H */
/* Editor directions:
 * vim:textwidth=78:tabstop=8:shiftwidth=2:autoindent:cindent
 */
