/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_strlen_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:35:52 by pscott            #+#    #+#             */
/*   Updated: 2018/12/02 18:45:35 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "strlen.h"

int	strlen_launcher(t_err_info *info)
{
	t_unit_test		*testlist;

	testlist = NULL;
	fw_putendl("\n\033[94mSTRLEN\n\033[0m");
	load_test(&strlen_basic, &testlist, "basic_test", 0);
	load_test(&strlen_empty, &testlist, "empty_test", 0);
	load_test(&strlen_verylong, &testlist, "verylong_test", 0);
	return (launch_test(&testlist, info));
}
