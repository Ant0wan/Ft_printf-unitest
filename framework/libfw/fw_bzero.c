/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:09:45 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/07 14:19:44 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

void	fw_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_ptr;

	i = -1;
	s_ptr = (unsigned char*)s;
	while (++i < n)
		s_ptr[i] = 0;
}
