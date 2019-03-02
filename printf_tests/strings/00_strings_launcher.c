/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strings_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:59:22 by abarthel          #+#    #+#             */
/*   Updated: 2019/02/11 18:22:38 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strings.h"

#include <stdio.h>

int	strings_launcher(t_err_info *info)
{
	t_unit_test		*testlist;

	testlist = NULL;
	puts("\n\e[38;5;123mstrings\n\033[0m");
/* LOAD TESTS */
	load_test(&multi_many2, &testlist, "multi_many2", 0);
	load_test(&multi_many, &testlist, "multi_many", 0);
	load_test(&prec_abuse, &testlist, "prec_abuse", 0);
	load_test(&width_abuse, &testlist, "width_abuse", 0);
	load_test(&prec_limit, &testlist, "prec_limit", 0);
	load_test(&width_limit, &testlist, "width_limit", 0);
	load_test(&width_large, &testlist, "width_large", 0);
	load_test(&wdpr_dosdos, &testlist, "wdpr_dosdos", 0);
	load_test(&width_prectw, &testlist, "width_prectw", 0);
	load_test(&prec_canyou, &testlist, "prec_canyou", 0);
	load_test(&easy_spaces, &testlist, "easy_spaces", 0);
	load_test(&easy_argfmt, &testlist, "easy_argfmt", 0);
	load_test(&easy_arg2fmt, &testlist, "easy_arg2fmt", 0);
	return (launch_test(&testlist, info));
}
