/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:14:04 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/06 17:37:31 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

char	*fw_strcpy(char *dst, const char *src)
{
	size_t	len;
	size_t	count;

	count = 0;
	len = fw_strlen(src);
	while (count < len)
	{
		dst[count] = src[count];
		++count;
	}
	dst[len] = '\0';
	return (dst);
}
