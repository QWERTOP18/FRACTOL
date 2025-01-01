/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:58 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/01 18:38:18 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

int	calc_mandelbrot(t_sys *sys)
{
	return (1);
}

int	calc_julia(t_sys *sys)
{
	return (1);
}

typedef int	(*t_iterate_f)(t_sys *sys);

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
			if (sys->iter[x][y] == sys->sup_iteri)
				sys->iter[x][y] += (iterate[sys->type])(sys);
			x++;
		}
		y++;
	}
}
