/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:14:47 by pscott            #+#    #+#             */
/*   Updated: 2019/02/14 13:05:19 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stdlib.h>

typedef struct			s_unit_test
{
	int					(*f)(void);
	char				*name;
	int					expected;
	struct s_unit_test	*next;
}						t_unit_test;

typedef struct			s_err_info
{
	int					err;
	int					total;
}						t_err_info;

int						load_test(int (*f)(void), t_unit_test **testlist, char *name, int expected);

int						launch_test(t_unit_test **testlist, t_err_info *info);

void					print_header(void);

int						process_launch(int (*f)(void));

int						exitstatus(int stat);

void					print_result(int stat, int expected);

int						print_usage(void);

void					print_score(int a, int b);

void					init_info(t_err_info *info);

void					print_test(char *name);

char					*strnew(size_t size);

#endif
