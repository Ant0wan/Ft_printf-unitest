/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_strjoin_empty_s2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:06:18 by pscott            #+#    #+#             */
/*   Updated: 2018/12/02 16:07:03 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int	strjoin_empty_s2(void)
{
	char *s1;
	char *s2;
	char *s3;
	char *res;

	s1 = "This is a test";
	s2 = "";
	s3 = "This is a test";
	res = ft_strjoin(s1, s2);
	if (fw_strcmp(s3, res) == 0 && res != s1)
	{
		if (res)
			free(res);
		return (0);
	}
	else
	{
		if (res && res != s1)
			free(res);
		return (-1);
	}
}
