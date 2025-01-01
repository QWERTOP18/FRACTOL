/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:53 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/01 10:03:54 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac_hook.h"

int	mouse_hook(int button, int x, int y, t_sys *sys)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom(sys, button, x, y);
	return (0);
}

int	key_hook(int key, t_sys *sys)
{
	if (key == ESCAPE)
		exit_hook(sys);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move(sys, key, x, y); // todo bitMsk を使って簡潔に
	return (0);
}

int	exit_hook(t_sys *sys)
{
	mlx_destroy_window(sys->mlx, sys->win);
	system_exit(sys, 0);
}
