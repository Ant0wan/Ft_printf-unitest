/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_function_tests.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:54:00 by abarthel          #+#    #+#             */
/*   Updated: 2019/01/22 16:47:16 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int		void_char_test(int len, void (*f)(char), char input)
{
	char	buffer[len + 1];
	int		stat;
	int		fd[2];

	buffer[len] = '\0';
	stat = 0;
	pipe(fd);
	if (fork() == 0)
	{
		close(1);
		dup2(fd[1], 1);
		f(input);
		return (0);
	}
	else
	{
		wait(&stat);
		read(fd[0], buffer, len);
		if (!(strncmp(buffer, &input, len)))
			return (0);
		else
			return (-1);
	}
}

int		void_str_test(int len, void (*f)(const char*), char *input)
{
	char	buffer[len + 1];
	int		stat;
	int		fd[2];

	buffer[len] = '\0';
	stat = 0;
	pipe(fd);
	if (fork() == 0)
	{
		close(1);
		dup2(fd[1], 1);
		f(input);
		return (0);
	}
	else
	{
		wait(&stat);
		read(fd[0], buffer, len);
		if (!(strncmp(buffer, input, len)))
			return (0);
		else
			return (-1);
	}
}

int		void_itoa_test(int len, void (*f)(int), int input, char *output)
{
	char	buffer[len + 1];
	int		stat;
	int		fd[2];

	buffer[len] = '\0';
	stat = 0;
	pipe(fd);
	if (fork() == 0)
	{
		close(1);
		dup2(fd[1], 1);
		f(input);
		return (0);
	}
	else
	{
		wait(&stat);
		read(fd[0], buffer, len);
		if (!(strncmp(buffer, output, len)))
			return (0);
		else
			return (-1);
	}
}
