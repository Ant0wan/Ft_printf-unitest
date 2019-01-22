/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_putchar_launcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:07:44 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/02 19:07:36 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "putchar.h"

int	putchar_launcher(t_err_info *info)
{
	t_unit_test *testlist;

	testlist = NULL;
	fw_putendl("\n\033[94mPUTCHAR\033[0m\n");
	load_test(&putchar_basic, &testlist, "basic_test", 0);
	load_test(&putchar_null, &testlist, "null_test", 0);
	return (launch_test(&testlist, info));
}
