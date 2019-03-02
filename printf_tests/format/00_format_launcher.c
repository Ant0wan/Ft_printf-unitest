/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_format_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:59:22 by abarthel          #+#    #+#             */
/*   Updated: 2019/02/11 18:22:38 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "format.h"

#include <stdio.h>

int	format_launcher(t_err_info *info)
{
	t_unit_test		*testlist;

	testlist = NULL;
	puts("\n\e[38;5;123mformat\n\033[0m");
/* LOAD TESTS */
	load_test(&op_fuckedup, &testlist, "op_fuckedup", 0);
	load_test(&op_sizeof, &testlist, "op_sizeof", 0);
	load_test(&easy_spper, &testlist, "easy_spper", 0);
	load_test(&easy_bracket, &testlist, "easy_bracket", 0);
	load_test(&easy_flagp, &testlist, "easy_flagp", 0);
	load_test(&easy_flag, &testlist, "easy_flag", 0);
	load_test(&easy_star, &testlist, "easy_star", 0);
	load_test(&easy_number, &testlist, "easy_number", 0);
	load_test(&easy_spec, &testlist, "easy_spec", 0);
	load_test(&easy_quote, &testlist, "easy_quote", 0);
	load_test(&easy_one, &testlist, "easy_one", 0);
	load_test(&easy_bckslsh, &testlist, "easy_bckslsh", 0);
	load_test(&easy_qtmark, &testlist, "easy_qtmark", 0);
	load_test(&easy_percent, &testlist, "easy_percent", 0);
	return (launch_test(&testlist, info));
}
