/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:44:24 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/01 18:50:17 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

void	fw_lstdelone(t_mylist **alst, void (*del)(void *, size_t))
{
	if (del && *alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
