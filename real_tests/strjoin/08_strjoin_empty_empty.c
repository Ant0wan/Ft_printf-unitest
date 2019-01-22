/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_strjoin_empty_empty.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:16:57 by pscott            #+#    #+#             */
/*   Updated: 2018/12/02 16:19:15 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int	strjoin_empty_empty(void)
{
	char *s1;
	char *s2;
	char *s3;
	char *res;

	s1 = "";
	s2 = "";
	s3 = "";
	res = ft_strjoin(s1, s2);
	if (fw_strcmp(s3, res) == 0 && res != s1 && res != s2)
	{
		if (res)
			free(res);
		return (0);
	}
	else
	{
		if (res && res != s1 && res != s2)
			free(res);
		return (-1);
	}
}
