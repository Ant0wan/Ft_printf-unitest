/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_conversions_launcher.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:59:22 by abarthel          #+#    #+#             */
/*   Updated: 2019/01/30 12:41:31 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "conversions.h"

#include <stdio.h>

int	conversions_launcher(t_err_info *info)
{
	t_unit_test		*testlist;

	testlist = NULL;
	puts("\n\033[94mConversions\n\033[0m");
	load_test(&int_test_01, &testlist, "int_test_01", 0);
	load_test(&int_test_02, &testlist, "int_test_02", 0);
	load_test(&int_test_03, &testlist, "int_test_03", 0);
	load_test(&int_test_04, &testlist, "int_test_04", 0);
	return (launch_test(&testlist, info));
}
