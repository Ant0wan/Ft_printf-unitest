/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_putnbr_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:07:44 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/02 20:16:56 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "putnbr.h"

int	putnbr_launcher(t_err_info *info)
{
	t_unit_test *testlist;

	testlist = NULL;
	fw_putendl("\n\033[94mPUTNBR\033[0m\n");
	load_test(&putnbr_basic, &testlist, "basic_test", 0);
	load_test(&putnbr_zero, &testlist, "zero_test", 0);
	load_test(&putnbr_negv, &testlist, "negv_test", 0);
	load_test(&putnbr_empty, &testlist, "empty_test", 0);
	load_test(&putnbr_overflow, &testlist, "overflow_test", 0);
	return (launch_test(&testlist, info));
}
