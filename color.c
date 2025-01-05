/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:56 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/05 18:58:49 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate.h"
#include "system.h"

unsigned int	determine_color(int iter, t_sys *sys)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	col;

	col = sys->col;
	if (iter >= sys->sup_iteri - ITER_STEP)
		return (0);
	r = iter * (col & 0xFF0000) % 0xFF;
	g = iter * (col & 0xFF00) % 0xFF;
	b = iter * (col & 0xFF) % 0xFF;
	return (r << 16 | g << 8 | b);
}
