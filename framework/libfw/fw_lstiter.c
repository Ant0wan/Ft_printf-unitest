/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:20:59 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/01 18:50:30 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

void	fw_lstiter(t_mylist *lst, void (*f)(t_mylist *elem))
{
	if (f && lst)
	{
		fw_lstiter(lst->next, f);
		f(lst);
	}
}
