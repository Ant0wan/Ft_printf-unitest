/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:28:19 by abarthel          #+#    #+#             */
/*   Updated: 2019/01/22 16:48:55 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void		print_header(void)
{
	puts("\033[93m");
	puts("         :::      ::::::::");
	puts("       :+:      :+:    :+:");
	puts("     +:+ +:+         +:+  ");
	puts("   +#+  +:+       +#+     |   |      _) |   __ __|         |");
	puts(" +#+#+#+#+#+   +#+        |   | __ \\  | __|    |  _ \\  __|");
	puts("__|");
	puts("      #+#    #+#");
	puts("          |   | |   | | |      |  __/\\__ \\ |");
	puts("     ###   ########.fr");
	puts("    \\___/_|  _|_|\\__|   _|\\___|____/\\__|");
	puts("");
	puts("\033[0m     version: \033[36mv0.1");
	puts("\033[0m     authors: \033[36mabarthel\033[0m, ");
	puts("\033[36mpscott\033[0m, ");
	puts("\033[36malesteph\033[0m");
	puts("");
	puts("");
}

void		print_result(int stat, int expected)
{
	if (stat == expected)
		puts("\033[32m[OK]\033[0m");
	else if (stat == 1 || stat == 0)
		puts("\033[31m[KO]\033[0m");
	else if (stat == 11)
		puts("\033[31m[SEGV]\033[0m");
	else if (stat == 10)
		puts("\033[31m[BUSE]\033[0m");
	else if (stat == -2)
		puts("Error from our side.");
	else if (stat == 14)
		puts("\033[31m[TIMEOUT]\033[0m");
	else
		puts("Exit not caught.");
}

void		print_score(int err, int total)
{
	puts("\nScore: ");
	printf("%d", total - err);
	putchar('/');
	printf("%d", total);
	puts(" valid tests.\n");
}

void		print_test(char *name)
{
	puts("\t> ");
	puts(name);
	puts("\t:\t");
}
