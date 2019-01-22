/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framework.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:56:16 by pscott            #+#    #+#             */
/*   Updated: 2018/12/02 18:25:00 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_unit_test	*create_list(int (*f)(void), char *name, t_unit_test *next, \
		int expected)
{
	t_unit_test *tmp;

	if (!(tmp = (t_unit_test*)malloc(sizeof(*tmp))))
		return (NULL);
	tmp->f = f;
	tmp->name = name;
	tmp->expected = expected;
	tmp->next = next;
	return (tmp);
}

void		list_append(t_unit_test *newlist, t_unit_test **testlist)
{
	t_unit_test *tmp;

	if (!testlist || !(*testlist) || !newlist)
		return ;
	tmp = (*testlist);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newlist;
}

int			load_test(int (*f)(void), t_unit_test **testlist, char *name, \
		int expected)
{
	if ((!testlist) || !(*testlist))
		(*testlist) = create_list(f, name, NULL, expected);
	else
		list_append(create_list(f, name, NULL, expected), testlist);
	return (1);
}

int			launch_test(t_unit_test **testlist, t_err_info *info)
{
	t_unit_test *tmp;
	int			ret;

	while (testlist && (*testlist)->next)
	{
		print_test((*testlist)->name);
		ret = process_launch((*testlist)->f);
		if (ret != (*testlist)->expected)
			info->err++;
		info->total++;
		print_result(ret, (*testlist)->expected);
		tmp = (*testlist);
		(*testlist) = (*testlist)->next;
		if (tmp)
			free(tmp);
	}
	print_test((*testlist)->name);
	ret = process_launch((*testlist)->f);
	if (ret != (*testlist)->expected)
		info->err++;
	info->total++;
	print_result(ret, (*testlist)->expected);
	if (*testlist)
		free(*testlist);
	return (0);
}
