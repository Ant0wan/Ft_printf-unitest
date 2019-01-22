/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 08:23:46 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/13 08:27:47 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

void	fw_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
		fw_putchar_fd('-', fd);
	nb = n < 0 ? n * -1 : n;
	if (nb >= 10)
	{
		fw_putnbr_fd(nb / 10, fd);
		fw_putchar_fd(nb % 10 + '0', fd);
	}
	else
		fw_putchar_fd(nb + '0', fd);
}
