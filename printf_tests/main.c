/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:25:22 by pscott            #+#    #+#             */
/*   Updated: 2019/02/11 17:43:37 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "launchers.h"

int	main(void)
{
	t_err_info	*info;
	int			ret;

	if (!(info = malloc(sizeof(t_err_info))))
		return (1);
	init_info(info);
	print_header();
/* FUNCTIONS CALL */
	strings_launcher(info);
	format_launcher(info);
	print_score(info->err, info->total);
	ret = info->err ? -1 : 0;
	if (info)
		free(info);
	return (ret);
}
