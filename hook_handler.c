/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:53 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/01 14:48:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_handler.h"






int	mouse_handler(int button, int x, int y, t_sys *sys)
{
	printf("key %X,x %d,y %d\n", button, x, y);
	if (button == SCROLL_UP)
	 	screen_zoom(sys, 1.25, x, y);
	if ( button == SCROLL_DOWN)
		screen_zoom(sys, 0.8, x, y);
	return (0);
}

int	key_handler(int key, t_sys *sys)
{
	printf("key %X\n", key);
	if (key == ESCAPE)
		exit_handler(sys);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		pan_screen(sys, key - LEFT);
	if ('i' <= key && key <= 'l')
		modify_coefficient(sys, key - 'i');

	return (0);
}

int	exit_handler(t_sys *sys)
{
	mlx_destroy_window(sys->mlx, sys->win);
	system_exit(sys, 0);
	return (0);
}
