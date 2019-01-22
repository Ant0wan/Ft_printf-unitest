/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_strlen_verylong.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:38:22 by pscott            #+#    #+#             */
/*   Updated: 2018/12/02 15:48:32 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"

int	strlen_verylong(void)
{
	if (ft_strlen("0123456789012345678901234567890123456789\t\t\tqwjkdsaoiwkjdlsjkwe\n\n   ##qw!!!!*\b\r\v\f") == fw_strlen("0123456789012345678901234567890123456789\t\t\tqwjkdsaoiwkjdlsjkwe\n\n   ##qw!!!!*\b\r\v\f"))
		return (0);
	else
		return (-1);
}
