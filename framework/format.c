/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:28:19 by abarthel          #+#    #+#             */
/*   Updated: 2019/02/11 18:30:39 by abarthel         ###   ########.fr       */
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
	puts("\e[38;5;35m");
	puts("   ______      _               ___       _     _       _                        ");
	puts("\e[38;5;36m  (_____ \\    (_)       _     / __)     (_)   (_)     (_)  _                _   ");
	puts("   _____) )___ _ ____ _| |_ _| |__ _____ _     _ ____  _ _| |_ _____  ___ _| |_ ");
	puts("  |  ____/ ___) |  _ (_   _|_   __|_____) |   | |  _ \\| (_   _) ___ |/___|_   _) ");
	puts("  | |   | |   | | | | || |_  | |        | |___| | | | | | | |_| ____|___ | | |_ ");
	puts("\e[38;5;37m  |_|   |_|   |_|_| |_| \\__) |_|         \\_____/|_| |_|_|  \\__)_____|___/   \\__)");	                                                                                
	puts(" ");
	puts("\e[0m     version:     \e[38;5;191mv2.0-script\e[0m");
	puts("     author:      \e[38;5;192mabarthel\e[0m");
	puts("     contributor: \e[38;5;193mpscott\e[0m");
	puts("");
}

void		print_result(int stat, int expected)
{
	if (stat == expected)
		printf("\e[38;5;82m[OK]\e[0m\n");
	else if (stat == RET_ERROR0 || stat == RET_ERROR1)
		printf("\e[38;5;196m[KO]\e[0m\n");
	else if (stat == SIGSEGV)
		printf("\e[38;5;196m[SEGV]\e[0m\n");
	else if (stat == SIGBUS)
		printf("\e[38;5;196m[BUSE]\e[0m\n");
	else if (stat == RET_CRASHFRAME)
		printf("Error from our side.\n");
	else if (stat == SIGALRM)
		printf("\e[38;5;196m[TIMEOUT]\e[0m\n");
	else
		printf("\e[38;5;226mExit not caught.\n");
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
	write(1, "> ", 3);
	write(1, name, strlen(name));
	write(1, ":\t", 3);
}
