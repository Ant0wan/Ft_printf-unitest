/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:48:12 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/10 15:02:42 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

char	*fw_strjoin(char const *s1, char const *s2)
{
	char	*cpy;

	if (s1 && s2)
		cpy = (char*)malloc(sizeof(*cpy) * (fw_strlen(s1) + fw_strlen(s2)) + 1);
	if (!s1 || !s2 || !cpy)
		return (NULL);
	cpy = fw_strcpy(cpy, s1);
	cpy = fw_strcat(cpy, s2);
	return (cpy);
}
