/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:31:23 by abarthel          #+#    #+#             */
/*   Updated: 2019/01/22 19:34:00 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	*ft_memalloc(size_t size)
{
	void	*p_mem;

	p_mem = (void*)malloc(size);
	if (!p_mem)
		return (NULL);
	bzero(p_mem, size);
	return (p_mem);
}

char		*strnew(size_t size)
{
	return (ft_memalloc(size + 1));
}
