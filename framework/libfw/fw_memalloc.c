/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:08:32 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/09 15:18:22 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

void	*fw_memalloc(size_t size)
{
	void	*p_mem;

	p_mem = (void*)malloc(size);
	if (!p_mem)
		return (NULL);
	fw_bzero(p_mem, size);
	return (p_mem);
}
