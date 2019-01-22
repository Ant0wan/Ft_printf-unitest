/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_empty_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:12:52 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/02 20:21:44 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

#define TEST (int)(NULL)

int	putnbr_empty(void)
{
	if (!(void_itoa_test(30, &ft_putnbr, TEST, "0")))
		return (0);
	else
		return (-1);
}
