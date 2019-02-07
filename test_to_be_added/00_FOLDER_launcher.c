/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_FOLDER_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:59:22 by abarthel          #+#    #+#             */
/*   Updated: 2019/02/07 18:06:15 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "FOLDER.h"

#include <stdio.h>

int	FOLDER_launcher(t_err_info *info)
{
	t_unit_test		*testlist;

	testlist = NULL;
	puts("\n\033[94mFOLDER\n\033[0m");
	load_test(&int_test_01, &testlist, "FOLDER_TYPE_NAME", 0);
	return (launch_test(&testlist, info));
}
