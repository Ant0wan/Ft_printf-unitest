/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:57:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/13 17:46:28 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

char	*fw_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	i = -1;
	cpy = (char*)malloc(sizeof(*cpy) * len + 1);
	if (!cpy || !s)
		return (NULL);
	while (++i < len)
		cpy[i] = s[start + i];
	cpy[i] = '\0';
	return (cpy);
}
