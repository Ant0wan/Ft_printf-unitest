/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_zero_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:12:52 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/02 20:05:50 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int	putnbr_zero(void)
{
	if (!(void_itoa_test(2, &ft_putnbr, 0, "0")))
		return (0);
	else
		return (-1);
}
