/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 10:13:54 by pscott            #+#    #+#             */
/*   Updated: 2018/12/02 16:14:16 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int	strjoin_basic(void)
{
	char *s1;
	char *s2;
	char *res;

	s1 = "This is a test";
	s2 = ", and this test is valid!";
	res = ft_strjoin(s1, s2);
	if (fw_strcmp(res, "This is a test, and this test is valid!") == 0)
	{
		if (res)
			free(res);
		return (0);
	}
	else
	{
		if (res)
			free(res);
		return (-1);
	}
}
