/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:50:36 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/13 21:38:00 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfw.h"

void	fw_print_tables(char **tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			fw_putchar(tab[i][j]);
			j++;
		}
		i++;
		fw_putchar('\n');
	}
}
