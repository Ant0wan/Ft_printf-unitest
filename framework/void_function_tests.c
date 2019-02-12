/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_function_tests.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:54:00 by abarthel          #+#    #+#             */
/*   Updated: 2019/02/12 13:55:05 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

#define BUFF 1024

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

int		void_printf_test(int (*f)(const char *restrict, ...), const char *restrict format, ...)
{
	va_list	ap;
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
		va_start(ap, format);
		ret = f(format, ap);
		write(ret_fd[1], &ret, sizeof(int));
		va_end(ap);
		return (0);
	}
	else
	{
		wait(&stat);
		read(fd[0], buffer, BUFF);
		read(ret_fd[0], &ret, sizeof(int));
		va_start(ap, format);
		ret2 = sprintf(buffer2, format, ap);
		va_end(ap);
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
