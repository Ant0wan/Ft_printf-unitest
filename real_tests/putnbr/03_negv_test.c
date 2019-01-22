/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_negv_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:12:52 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/02 21:16:43 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int	putnbr_negv(void)
{
	if (!(void_itoa_test(4, &ft_putnbr, (-42), "-42")))
		return (0);
	else
		return (-1);
}
