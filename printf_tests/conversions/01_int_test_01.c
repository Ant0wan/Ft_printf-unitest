/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_int_test_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:01:48 by abarthel          #+#    #+#             */
/*   Updated: 2019/01/22 19:23:25 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#define BUFF 2048 // Can change buffer size

int		int_test_01(void)
{
	// TEST PARAMETERS //
	int	val = 42;
	char *str = "Hello my name is Antoine and I study at %d\n";


	// Testing function
	char	buffer[BUFF + 1];
	char	buffer2[BUFF + 1];
	int		stat;
	int		fd[2];

	buffer[BUFF] = '\0';
	buffer2[BUFF] = '\0';
	stat = 0;
	pipe(fd);
	if (fork() == 0)
	{
		close(1);
		dup2(fd[1], 1);
		printf(str, val); // Here is the test to modify
		return (0);
	}
	else
	{
		wait(&stat);
		read(fd[0], buffer, BUFF);
		sprintf(buffer2, str, val); // Here is the test to modify		
		if (!(strcmp(buffer, buffer2)))
			return (0);
		else
			return (-1);
	}
}
