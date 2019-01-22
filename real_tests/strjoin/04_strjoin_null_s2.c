/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_strjoin_null_s2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:01:44 by pscott            #+#    #+#             */
/*   Updated: 2018/12/02 16:02:23 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int	strjoin_null_s2(void)
{
	char *s1;
	char *s2;
	char *s3;
	char *res;

	s1 = NULL;
	s2 = ", and this test is valid!";
	s3 = ", and this test is valid!";
	res = ft_strjoin(s1, s2);
	if (fw_strcmp(s3, res) == 0 && res != s2)
	{
		if (res)
			free(res);
		return (0);
	}
	else
	{
		if (res && res != s2)
			free(res);
		return (-1);
	}
}
