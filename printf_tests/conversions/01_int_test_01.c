/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_int_test_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:01:48 by abarthel          #+#    #+#             */
/*   Updated: 2019/01/30 12:44:49 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#include <unistd.h>
#include <stdio.h>
#include <strings.h>

#define BUFF 2048

int		int_test_01(void)
{
	// TEST ARGUMENTS //
	int	val = 42;
	char *str = "Hello I study at %d\n";


	// Testing function
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
		printf(str, val); // Modify here the number of parameters
		return (0);
	}
	else
	{
		wait(&stat);
		read(fd[0], buffer, BUFF);
		sprintf(buffer2, str, val); // Modify here the number of parameters
		if (!(strcmp(buffer, buffer2)))
			return (0);
		else
			return (-1);
	}
}
