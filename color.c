/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:56 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/01 19:07:54 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

unsigned	determine_color(int iter, t_sys *sys)
{
	unsigned r;
	unsigned g;
	unsigned b;
	if (iter == sys->sup_iteri)
		return (0);
	r = 0x00;
	g = 0x00;
	b = 0xFF;
	return (r << 16 | g << 8 | b);
}