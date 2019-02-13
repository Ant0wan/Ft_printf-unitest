/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwprintf_disp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:37:47 by abarthel          #+#    #+#             */
/*   Updated: 2019/01/31 12:16:55 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fwprintf_disp.h"
#include "struct_fwprintf_disp.h"

#include <stdlib.h>

#include "ft_wchar.h"

static const t_operator	g_flag[] =
{
	{ L" ", NULL},
	{ L"+", NULL},
	{ L"-", NULL},
	{ L"#", NULL},
	{ L"0", NULL},
	{ L"\'", NULL},
	{ L"I", NULL},
	{ L"\0", NULL}
};

static const t_operator	g_precision[] =
{
	{ L"o", NULL},
	{ L"x", NULL},
	{ L"X", NULL},
	{ L"e", NULL},
	{ L"E", NULL},
	{ L"g", NULL},
	{ L"G", NULL},
	{ L"\0", NULL}
};

static const t_operator	g_specifier[] =
{
	{ L"c", NULL},
	{ L"hd", NULL},
	{ L"hu", NULL},
	{ L"u", NULL},
	{ L"u", NULL},
	{ L"f", NULL},
	{ L"d", NULL},
	{ L"i", NULL},
	{ L"ld", NULL},
	{ L"lu", NULL},
	{ L"lld", NULL},
	{ L"llu", NULL},
	{ L"lf", NULL},
	{ L"Lf", NULL},
	{ L"s", NULL},
	{ L"\0", NULL}
};

void					*dispatcher(wchar_t *str)
{
	int	i;

	i = 0;
	while (g_specifier[i].type[0] && ft_wcscmp(g_specifier[i].type, str))
		++i;
	if (g_specifier[i].type[0])
		return (g_specifier[i].f);
	return (NULL);
}
