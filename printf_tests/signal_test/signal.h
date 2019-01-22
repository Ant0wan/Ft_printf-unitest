/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:15:42 by pscott            #+#    #+#             */
/*   Updated: 2018/12/02 18:39:54 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

int		signal_basic_test(void);
int		signal_wrong_test(void);
int		signal_null_test(void);
int		signal_bus_test(void);
int		signal_timeout_test(void);
int		signal_asksegv_test(void);
int		signal_askbus_test(void);
int		signal_askwrong_test(void);
int		signal_asktimeout_test(void);
#endif
