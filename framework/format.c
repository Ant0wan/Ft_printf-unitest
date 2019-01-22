/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:28:19 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/06 10:47:45 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void		print_header(void)
{
	fw_putendl("\033[93m");
	fw_putendl("         :::      ::::::::");
	fw_putendl("       :+:      :+:    :+:");
	fw_putendl("     +:+ +:+         +:+  ");
	fw_putendl("   +#+  +:+       +#+     |   |      _) |   __ __|         |");
	fw_putstr(" +#+#+#+#+#+   +#+        |   | __ \\  | __|    |  _ \\  __|");
	fw_putendl("__|");
	fw_putstr("      #+#    #+#");
	fw_putendl("          |   | |   | | |      |  __/\\__ \\ |");
	fw_putstr("     ###   ########.fr");
	fw_putendl("    \\___/_|  _|_|\\__|   _|\\___|____/\\__|");
	fw_putendl("");
	fw_putstr("\033[0m     version: \033[36mv0.1");
	fw_putstr("\033[0m     authors: \033[36mabarthel\033[0m, ");
	fw_putstr("\033[36mpscott\033[0m, ");
	fw_putstr("\033[36malesteph\033[0m");
	fw_putendl("");
	fw_putendl("");
}

void		print_result(int stat, int expected)
{
	if (stat == expected)
		fw_putendl("\033[32m[OK]\033[0m");
	else if (stat == 1 || stat == 0)
		fw_putendl("\033[31m[KO]\033[0m");
	else if (stat == 11)
		fw_putendl("\033[31m[SEGV]\033[0m");
	else if (stat == 10)
		fw_putendl("\033[31m[BUSE]\033[0m");
	else if (stat == -2)
		fw_putendl("Error from our side.");
	else if (stat == 14)
		fw_putendl("\033[31m[TIMEOUT]\033[0m");
	else
		fw_putendl("Exit not caught.");
}

void		print_score(int err, int total)
{
	fw_putstr("\nScore: ");
	fw_putnbr(total - err);
	fw_putchar('/');
	fw_putnbr(total);
	fw_putstr(" valid tests.\n");
}

void		print_test(char *name)
{
	fw_putstr("\t> ");
	fw_putstr(name);
	fw_putstr("\t:\t");
}
