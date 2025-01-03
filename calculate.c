/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:58 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/03 16:16:15 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

int	calc_mandelbrot(t_complex *c_num, t_sys *sys)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < ITER_STEP)
	{
		tmp = c_num->im * c_num->im - c_num->re * c_num->re;
		c_num->im = 2.0 * c_num->im * c_num->re;
		c_num->re = tmp;
		if (c_num->im * c_num->im + c_num->re * c_num->re >= 4)
			return (i);
		i++;
	}
	return (i);
}

int	calc_julia(t_complex *c_num, t_sys *sys)
{
	return (1);
}
//                                    \---double point???? todo
typedef int	(*t_iterate_f)(t_complex *c_num, t_sys *sys);

#define DEBAG += 1

void	calculate(t_sys *sys)
{
	int					y;
	int					x;
	static t_iterate_f	iterate[] = {calc_mandelbrot, calc_julia};

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (sys->iter[x][y] == 0)
			{
				sys->val[y][x].re = sys->screen.base.re + (double)x
					* sys->screen.width / SCREEN_WIDTH;
				sys->val[y][x].im = sys->screen.base.im + (double)y
					* sys->screen.height / SCREEN_HEIGHT;
			}
			if (sys->iter[x][y] == sys->sup_iteri)
				sys->iter[x][y] = (*iterate[sys->type])(&sys->val[y][x], sys);
			// sys->iter[x][y] += (*iterate[sys->type])(&sys->val[y][x],
			//		sys);
			render_pixel(sys, x, y, determine_color(sys->iter[x][y], sys));
			// #ifdef DEBUG
			// 			printf("iter %d\n", sys->iter[x][y]);
			// 			fflush(stdout);
			// #endif
			x++;
		}
		y++;
	}
}
