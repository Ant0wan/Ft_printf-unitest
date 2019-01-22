/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 07:11:32 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/13 08:02:36 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

void	fw_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
		fw_putchar('-');
	nb = n < 0 ? n * -1 : n;
	if (nb >= 10)
	{
		fw_putnbr(nb / 10);
		fw_putchar(nb % 10 + '0');
	}
	else
		fw_putchar(nb + '0');
}
