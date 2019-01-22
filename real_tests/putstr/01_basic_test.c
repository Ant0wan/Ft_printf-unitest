/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:12:52 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/02 20:39:51 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int	putstr_basic(void)
{
	if (!(void_str_test(24, &ft_putstr, "pscott c'est styleeeee !!")))
		return (0);
	else
		return (-1);
}
