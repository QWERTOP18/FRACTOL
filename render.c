/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:17 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/03 16:07:58 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

void	render_pixel(t_sys *sys, int x, int y, int color)
{
	char	*dst;

	dst = sys->img.addr + (y * sys->img.line_length + x
			* (sys->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
