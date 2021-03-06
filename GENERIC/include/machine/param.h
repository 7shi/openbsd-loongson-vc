/* $OpenBSD: param.h,v 1.1.1.1 2009/12/25 21:04:47 miod Exp $ */
/* public domain */

#ifndef _MACHINE_PARAM_H_
#define _MACHINE_PARAM_H_

#define	MACHINE		"loongson"
#define	_MACHINE	loongson
#define MACHINE_ARCH	"mips64el"
#define _MACHINE_ARCH	mips64el

#define MID_MACHINE	MID_MIPS64

/*
 * The Loongson level 1 cache expects software to prevent virtual
 * aliases. Unfortunately, since this cache is physically tagged,
 * this would require all virtual address to have the same bits 14
 * and 13 as their physical addresses, which is not something the
 * kernel can guarantee unless the page size is at least 16KB.
 */
#define	PAGE_SHIFT	14

#include <mips64/param.h>

#endif	/* _MACHINE_PARAM_H_ */
