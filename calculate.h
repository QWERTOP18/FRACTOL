/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:39:56 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/03 19:43:52 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATE_H
# define CALCULATE_H

# include "system.h"

typedef int		(*t_iterate_f)(int y, int x, t_complex *c_num, t_sys *sys);

int    calc_0(int y, int x, t_complex *c_num, t_sys *sys);
int    calc_1(int y, int x, t_complex *c_num, t_sys *sys);
int    calc_2(int y, int x, t_complex *c_num, t_sys *sys);
int    calc_3(int y, int x, t_complex *c_num, t_sys *sys);
#endif