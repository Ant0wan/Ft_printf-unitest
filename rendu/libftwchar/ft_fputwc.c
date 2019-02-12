/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputwc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:07:08 by abarthel          #+#    #+#             */
/*   Updated: 2019/02/02 14:31:02 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

#include <stdlib.h>
#include <unistd.h>

#include "utf8.h"

#define RET_ERROR         -1
#define UTF8ENCODING_SIZE  4

int	ft_fputwc(wchar_t wc, int fd)
{
	char	buf[4];

	if (wc >= 0x00)
	{
		if (wc <= 0x007F)
			return ((write(fd, &wc, sizeof(wc))) == RET_ERROR
					? RET_ERROR : (int)wc);
		else
		{
			if (utf8_encoder(&wc) == RET_ERROR)
				return (RET_ERROR);
			buf[0] = wc >> 24;
			buf[1] = wc >> 16;
			buf[2] = wc >> 8;
			buf[3] = wc;
			return ((write(fd, buf, UTF8ENCODING_SIZE)) == RET_ERROR
					? RET_ERROR : (int)wc);
		}
	}
	else
		return (RET_ERROR);
}
