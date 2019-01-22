/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:28:48 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/14 16:24:11 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

void	fw_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = -1;
	if (s && f)
		while (++i < fw_strlen(s))
			f(i, &s[i]);
}
