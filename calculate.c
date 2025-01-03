/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:58 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/03 18:23:01 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"
#include <math.h>

int	calc_mandelbrot(int y, int x, t_complex *c_num, t_sys *sys)
{
	int			i;
	double		tmp;
	t_complex	z_num;

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
		c_num->im = 2.0 * c_num->im * c_num->re + z_num.im;
		c_num->re = tmp + z_num.re;
		if (c_num->im * c_num->im + c_num->re * c_num->re >= 4)
			return (i);
		i++;
	}
	return (i);
}

int	calc_julia(int y, int x, t_complex *c_num, t_sys *sys)
{
	int		i;
	double	tmp;

	i = 0;
	if (sys->iter[y][x] == 0)
	{
		c_num->re = sys->screen.base.re + (double)x * sys->screen.width
			/ SCREEN_WIDTH;
		c_num->im = sys->screen.base.im + (double)y * sys->screen.height
			/ SCREEN_HEIGHT;
	}
	while (i < ITER_STEP)
	{
		tmp = c_num->im * c_num->im - c_num->re * c_num->re;
		c_num->im = 2.0 * c_num->im * c_num->re + sys->coef.im;
		c_num->re = tmp + sys->coef.re;
		if (c_num->im * c_num->im + c_num->re * c_num->re >= 4)
			return (i);
		i++;
	}
	return (i);
}
int	calc_burningship(int y, int x, t_complex *c_num, t_sys *sys)
{
	int			i;
	double		tmp;
	t_complex	z_num;

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

//                                    \---double point???? todo

#define DEBAG += 1

void	calculate(t_sys *sys)
{
	int					y;
	int					x;
	static t_iterate_f	iterate[] = {calc_mandelbrot, calc_julia,
			calc_burningship};

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (sys->iter[y][x] == sys->sup_iteri)
				sys->iter[y][x] += (*iterate[sys->type])(y, x, &sys->val[y][x],
						sys);
			render_pixel(sys, y, x, determine_color(sys->iter[x][y], sys));
			x++;
		}
		y++;
	}
	sys->sup_iteri = fmin(1000, sys->sup_iteri + ITER_STEP);
	if (sys->sup_iteri < 200)
		printf("iter %d\n", sys->sup_iteri);
}
