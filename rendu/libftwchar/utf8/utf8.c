/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:54:10 by abarthel          #+#    #+#             */
/*   Updated: 2019/02/02 13:31:38 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utf8.h"

#include <stdlib.h>
#include <unistd.h>

#define BYTE_WCHAR 4
#define RET_ERROR -1

static int	m0x07ff_utf8(wchar_t *wc)
{
	*wc = ((*wc << 16) & ~0xFFC0FFFF) | ((*wc << 23) & ~0xE0FFFFFF);
	*wc ^= 0xC0000000 | 0x800000;
	return ((int)*wc);
}

static int	m0xffff_utf8(wchar_t *wc)
{
	*wc = ((*wc << 12) & ~0xF0FFFFFF) | ((*wc << 10) & ~0xFFC0FFFF)
		| ((*wc << 8) & ~0xFFFFC0FF);
	*wc ^= 0xE0000000 | 0x800000 | 0x8000;
	return ((int)*wc);
}

static int	m0x10ffff_ut8(wchar_t *wc)
{
	*wc = ((*wc << 7) & ~0xF8FFFFFF) | ((*wc << 4) & ~0xFFC0FFFF)
		| ((*wc << 2) & ~0xFFFFC0FF) | (*wc & ~0xFFFFFFC0);
	*wc ^= 0xF0000000 | 0x800000 | 0x8000 | 0x80;
	return ((int)*wc);
}

int			utf8_encoder(wchar_t *wc)
{
	if (sizeof(wchar_t) != BYTE_WCHAR || *wc < 0)
		return (RET_ERROR);
	else if (*wc <= 0x007F)
		return ((int)*wc);
	else if (*wc <= 0x07FF)
		return (m0x07ff_utf8(wc));
	else if (*wc <= 0xFFFF)
		return (m0xffff_utf8(wc));
	else if (*wc <= 0x10FFFF)
		return (m0x10ffff_ut8(wc));
	else
		return (RET_ERROR);
}
