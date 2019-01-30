/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_int_test_03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2039/03/22 18:03:48 by abarthel          #+#    #+#             */
/*   Updated: 2019/01/30 12:45:05 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#include <stdio.h>
#include <unistd.h>
#include <strings.h>

#define BUFF 2048

int		int_test_03(void)
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
		printf("4567 |%-10T%5d| plip\n", 12); // Modify here the number of parameters
		return (0);
	}
	else
	{
		wait(&stat);
		read(fd[0], buffer, BUFF);
		sprintf(buffer2, "4567 |%-10T%5d| plip\n", 12); // Modify here the number of parameters
		if (!(strcmp(buffer, buffer2)))
			return (0);
		else
			return (-1);
	}
}
