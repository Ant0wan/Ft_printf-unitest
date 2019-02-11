/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_FOLDER_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:59:22 by abarthel          #+#    #+#             */
/*   Updated: 2019/02/11 18:22:38 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "FOLDER.h"

#include <stdio.h>

int	FOLDER_launcher(t_err_info *info)
{
	t_unit_test		*testlist;

	testlist = NULL;
	puts("\n\e[38;5;123mFOLDER\n\033[0m");
/* LOAD TESTS */
	return (launch_test(&testlist, info));
}
