/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:56 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/04 16:36:08 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

unsigned int	determine_color(int iter, t_sys *sys)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (iter == ITER_STEP)
		return (0);
	r = iter * 5 % 0xFF;
	g = iter * 3 % 0xFF;
	b = iter * 7 % 0xFF;
	return (r << 16 | g << 8 | b);
}
