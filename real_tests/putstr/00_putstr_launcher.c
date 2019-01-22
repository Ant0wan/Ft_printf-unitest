/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_putstr_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:07:44 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/02 21:07:20 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "putstr.h"

int	putstr_launcher(t_err_info *info)
{
	t_unit_test *testlist;

	testlist = NULL;
	fw_putendl("\n\033[94mPUTSTR\033[0m\n");
	load_test(&putstr_basic, &testlist, "basic_test", 0);
	load_test(&putstr_null, &testlist, "null_test", 14);
	return (launch_test(&testlist, info));
}
