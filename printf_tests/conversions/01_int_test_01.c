/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_int_test_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:01:48 by abarthel          #+#    #+#             */
/*   Updated: 2019/02/07 17:36:52 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#include <unistd.h>
#include <stdio.h>
#include <strings.h>

#define ARG_TEST "Hello World !"

int		int_test_01(void)
{
	if (!(void_printf_test(ARG_TEST)))
		return (0);
	else
		return (-1);
}
