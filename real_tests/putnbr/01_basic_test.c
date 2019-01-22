/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:12:52 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/02 20:05:25 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int	putnbr_basic(void)
{
	if (!(void_itoa_test(6, &ft_putnbr, 1250, "1250")))
		return (0);
	else
		return (-1);
}
