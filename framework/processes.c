/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:38:05 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/02 15:16:48 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <sys/wait.h>

int		process_launch(int (*f)(void))
{
	int		stat;
	int		ret;

	stat = 0;
	ret = 0;
	if (fork() == 0)
	{
		alarm(TIMEOUT);
		ret = f();
		if (ret == 0)
			exit(0);
		else if (ret == -1)
			exit(1);
	}
	else
		wait(&stat);
	return (exitstatus(stat));
}

int		exitstatus(int stat)
{
	if (WIFEXITED(stat))
		return (WEXITSTATUS(stat));
	if (WIFSIGNALED(stat))
		return (WTERMSIG(stat));
	return (-2);
}
