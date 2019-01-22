/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:12:52 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/02 20:16:10 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

#define TEST (-214748364) * (-15)

int	putnbr_overflow(void)
{
	if (!(void_itoa_test(30, &ft_putnbr, TEST, "-1073741836")))
		return (0);
	else
		return (-1);
}
