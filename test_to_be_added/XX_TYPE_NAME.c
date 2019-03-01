/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   XX_TYPE_NAME.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:01:48 by abarthel          #+#    #+#             */
/*   Updated: 2019/03/01 11:18:28 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rendu/libftprintf/ft_printf.h" // to change with correct path
#include "libunit.h"

#include <unistd.h>
#include <stdio.h>
#include <strings.h>

#define BUFF 1024
#define ARG_TEST XXX

int		TYPE_NAME(void)
{
	char	*buffer;
	char	*buffer2;
	int		stat;
	int		fd[2];
	int		ret_fd[2];
	int		ret;
	int		ret2;

	buffer = strnew(BUFF);
	buffer2 = strnew(BUFF);
	stat = 0;
	pipe(fd);
	pipe(ret_fd);
	if (fork() == 0)
	{
		close(1);
		dup2(fd[1], 1);
//		dup2(2, 1); // TESTS
		ret = ft_printf(ARG_TEST);
		write(ret_fd[1], &ret, sizeof(int));
		return (0);
	}
	else
	{
		wait(&stat);
		read(fd[0], buffer, BUFF);
		read(ret_fd[0], &ret, sizeof(int));
		ret2 = sprintf(buffer2, ARG_TEST);
		if (!(strcmp(buffer, buffer2)) && ret == ret2)
		{
			free(buffer);
			free(buffer2);
			return (0);
		}
		else
		{
			free(buffer);
			free(buffer2);
			return (-1);
		}
	}
}
