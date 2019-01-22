/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:28:01 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/01 18:50:52 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

t_mylist	*fw_lstnew(void const *content, size_t content_size)
{
	t_mylist	*new;

	new = (t_mylist*)malloc(sizeof(t_mylist));
	if (!new)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	new->content = fw_strdup(content);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
