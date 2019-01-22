/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strncpy_launcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 10:12:50 by pscott            #+#    #+#             */
/*   Updated: 2018/12/02 18:45:15 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strjoin.h"

int	strjoin_launcher(t_err_info *info)
{
	t_unit_test	*testlist;

	testlist = NULL;
	fw_putendl("\n\033[94mSTRJOIN\n\033[0m");
	load_test(&strjoin_basic, &testlist, "basic_test", 0);
	load_test(&strjoin_basic2, &testlist, "wrong_test", 0);
	load_test(&strjoin_s1_null, &testlist, "s1_null_test", 0);
	load_test(&strjoin_null_s2, &testlist, "null_s2_test", 0);
	load_test(&strjoin_s1_empty, &testlist, "s1_empty_test", 0);
	load_test(&strjoin_empty_s2, &testlist, "empty_s2_test", 0);
	load_test(&strjoin_null_null, &testlist, "null_test", 0);
	load_test(&strjoin_empty_empty, &testlist, "empty_test", 0);
	return (launch_test(&testlist, info));
}
