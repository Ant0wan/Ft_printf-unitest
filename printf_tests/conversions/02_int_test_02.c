/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_int_test_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2029/02/22 18:02:48 by abarthel          #+#    #+#             */
/*   Updated: 2019/01/30 12:44:57 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#include <unistd.h>
#include <stdio.h>
#include <strings.h>

#define BUFF 2048

int		int_test_02(void)
{
	char	*buffer;
	char	*buffer2;
	int		stat;
	int		fd[2];

	buffer = strnew(BUFF);
	buffer2 = strnew(BUFF);
	stat = 0;
	pipe(fd);
	if (fork() == 0)
	{
		close(1);
		dup2(fd[1], 1);
		printf("|%12s|\n", "str\0hidden"); // Modify here the number of parameters
		return (0);
	}
	else
	{
		wait(&stat);
		read(fd[0], buffer, BUFF);
		sprintf(buffer2, "|%12s|\n", "str\0hidden"); // Modify here the number of parameters
		if (!(strcmp(buffer, buffer2)))
			return (0);
		else
			return (-1);
	}
}
