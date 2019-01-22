/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:42:17 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/08 15:45:49 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

size_t		fw_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldest;
	size_t	lsrc;
	size_t	i;

	ldest = fw_strlen(dst);
	lsrc = fw_strlen(src);
	i = fw_strlen(dst);
	while (i < size - 1 && *src && size != 0)
	{
		dst[i] = *src;
		++i;
		++src;
	}
	dst[i] = '\0';
	return ((size < ldest) ? size + lsrc : ldest + lsrc);
}
