/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:58 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/01 10:03:58 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "system.h"



void	calculate(t_sys *sys)
{
	t_complex c;
    static void **(*calculate)(t_sys *sys) = {calculate_mandelbrot, calculate_julia};

	c.im = 0;
	while (c.im < HEIGHT)
	{
		c.re = 0;
		while (c.re < WIDTH)
		{
            
			c.re++;
		}
		c.im++;
	}
}