/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:56 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/04 16:51:33 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

unsigned int	determine_color(int iter, t_sys *sys)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	col;

	col = sys->col;
	if (iter == ITER_STEP)
		return (0);
	r = iter * (col & 0xFF0000) % 0xFF;
	g = iter * (col & 0xFF00) % 0xFF;
	b = iter * (col & 0xFF) % 0xFF;
	return (r << 16 | g << 8 | b);
}
