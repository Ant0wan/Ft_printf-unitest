/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_signal_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:43:48 by pscott            #+#    #+#             */
/*   Updated: 2018/12/02 18:48:28 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "signal.h"

int	signal_launcher(t_err_info *info)
{
	t_unit_test		*testlist;

	testlist = NULL;
	fw_putendl("\n\033[94mSIGNAL\n\033[0m");
	load_test(&signal_basic_test, &testlist, "basic_test", 0);
	load_test(&signal_wrong_test, &testlist, "wrong_test", 0);
	load_test(&signal_null_test, &testlist, "null_test", 0);
	load_test(&signal_bus_test, &testlist, "bus_test", 0);
	load_test(&signal_timeout_test, &testlist, "timeout", 0);
	load_test(&signal_asksegv_test, &testlist, "ask_segv", 11);
	load_test(&signal_askbus_test, &testlist, "ask_buse", 10);
	load_test(&signal_askwrong_test, &testlist, "ask_wrong", 1);
	load_test(&signal_asktimeout_test, &testlist, "ask_timeout", 14);
	return (launch_test(&testlist, info));
}
