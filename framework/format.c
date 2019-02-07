/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:28:19 by abarthel          #+#    #+#             */
/*   Updated: 2019/02/07 18:28:19 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <strings.h>

#define RET_ERROR0		0
#define RET_ERROR1		1
#define RET_CRASHFRAME -2


void		print_header(void)
{
	puts("\033[96m");
	puts("   ______      _               ___       _     _       _                        ");
	puts("  (_____ \\    (_)       _     / __)     (_)   (_)     (_)  _                _   ");
	puts("   _____) )___ _ ____ _| |_ _| |__ _____ _     _ ____  _ _| |_ _____  ___ _| |_ ");
	puts("  |  ____/ ___) |  _ (_   _|_   __|_____) |   | |  _ \\| (_   _) ___ |/___|_   _) ");
	puts("  | |   | |   | | | | || |_  | |        | |___| | | | | | | |_| ____|___ | | |_ ");
	puts("  |_|   |_|   |_|_| |_| \\__) |_|         \\_____/|_| |_|_|  \\__)_____|___/   \\__)");	                                                                                
	puts(" ");
	puts("\033[0m     version:     \033[93mv1.0-stdio\033[0m");
	puts("     author:      \033[93mabarthel\033[0m");
	puts("     contributor: \033[93mpscott\033[0m");
	puts("                  \033[93malesteph\033[0m");
	puts("                  \033[93mjkettani\033[0m");
	puts("");
}

void		print_result(int stat, int expected)
{
	if (stat == expected)
		printf("\033[32m[OK]\033[0m\n");
	else if (stat == RET_ERROR0 || stat == RET_ERROR1)
		printf("\033[31m[KO]\033[0m\n");
	else if (stat == SIGSEGV)
		printf("\033[31m[SEGV]\033[0m\n");
	else if (stat == SIGBUS)
		printf("\033[31m[BUSE]\033[0m\n");
	else if (stat == RET_CRASHFRAME)
		printf("Error from our side.\n");
	else if (stat == SIGALRM)
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
