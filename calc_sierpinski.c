/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sierpinski.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:38:24 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/03 19:38:46 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"
#include <math.h>

/* SIERPINSKI */
int	calc_3(int y, int x, t_complex *c_num, t_sys *sys)
{
	int i;
	double tmp;
	t_complex z_num;

	i = 0;
	if (sys->iter[y][x] == 0)
	{
		c_num->re = 0.0;
		c_num->im = 0.0;
	}
	z_num.re = sys->screen.base.re + (double)x * sys->screen.width
		/ SCREEN_WIDTH;
	z_num.im = sys->screen.base.im + (double)y * sys->screen.height
		/ SCREEN_HEIGHT;
	while (i < ITER_STEP)
	{
		tmp = c_num->im * c_num->im - c_num->re * c_num->re;
		c_num->im = fabs(2.0 * c_num->im * c_num->re) + z_num.im;
		c_num->re = tmp + z_num.re;
		if (c_num->im * c_num->im + c_num->re * c_num->re >= 4)
			return (i);
		i++;
	}
	return (i);
}