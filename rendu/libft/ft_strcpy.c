/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:14:04 by abarthel          #+#    #+#             */
/*   Updated: 2019/01/29 12:47:38 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	len;
	size_t	count;

	count = 0;
	len = ft_strlen(src);
	while (count < len)
	{
		dst[count] = src[count];
		++count;
	}
	dst[len] = '\0';
	return (dst);
}
