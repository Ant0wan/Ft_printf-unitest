/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_strjoin_null_null.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:15:52 by pscott            #+#    #+#             */
/*   Updated: 2018/12/02 16:16:39 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int	strjoin_null_null(void)
{
	char *s1;
	char *s2;
	char *s3;
	char *res;

	s1 = NULL;
	s2 = NULL;
	s3 = NULL;
	res = ft_strjoin(s1, s2);
	if (res == NULL)
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
