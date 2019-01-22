/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:28:19 by abarthel          #+#    #+#             */
/*   Updated: 2019/01/22 17:27:51 by abarthel         ###   ########.fr       */
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
	puts("\033[0m     version: \033[36mv1.0-stdio");
	puts("\033[0m     authors: \033[36mabarthel\033[0m, ");
	puts("\033[0 contributors: \033[36mpscott\033[0m ");
	puts("");
	puts("");
}

void		print_result(int stat, int expected)
{
	if (stat == expected)
		printf("\033[32m[OK]\033[0m\n");
	else if (stat == 1 || stat == 0)
		printf("\033[31m[KO]\033[0m\n");
	else if (stat == 11)
		printf("\033[31m[SEGV]\033[0m\n");
	else if (stat == 10)
		printf("\033[31m[BUSE]\033[0m\n");
	else if (stat == -2)
		printf("Error from our side.\n");
	else if (stat == 14)
		printf("\033[31m[TIMEOUT]\033[0m\n");
	else
		printf("Exit not caught.\n");
}

void		print_score(int err, int total)
{
	printf("\nScore: ");
	printf("%d", total - err);
	printf("/");
	printf("%d", total);
	printf(" valid tests.\n");
}

void		print_test(char *name)
{
	write(1, "\t> ", 3);
	write(1, name, strlen(name));
	write(1, "\t:\t", 3);
}
