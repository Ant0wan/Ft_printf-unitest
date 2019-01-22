/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:56:43 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/01 18:50:46 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

t_mylist	*fw_lstmap(t_mylist *lst, t_mylist *(*f)(t_mylist *elem))
{
	t_mylist	*new;

	new = NULL;
	if (f && lst)
	{
		new = (t_mylist*)malloc(sizeof(t_mylist));
		if (!new)
			return (NULL);
		new = f(lst);
		new->next = fw_lstmap(lst->next, f);
	}
	return (new);
}
