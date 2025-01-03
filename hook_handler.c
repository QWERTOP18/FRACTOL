/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:53 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/03 18:03:07 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_handler.h"

int	mouse_handler(int button, int x, int y, t_sys *sys)
{
	printf("key %X,x %d,y %d\n", button, x, y);
	if (button == SCROLL_UP)
		zoom_screen(sys, 1.25, x, y);
	if (button == SCROLL_DOWN)
		zoom_screen(sys, 0.8, x, y);
	return (0);
}

int	key_handler(int key, t_sys *sys)
{
	if (key == ESCAPE)
		exit_handler(sys);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		pan_screen(sys, key - LEFT);
	if ('i' <= key && key <= 'l')
		modify_coefficient(sys, key - 'i');
	if (key == 'c')
		modify_color_range(sys, key - 'c');
	return (0);
}

int	exit_handler(t_sys *sys)
{
	mlx_destroy_image(sys->mlx, sys->img.img);
	mlx_destroy_window(sys->mlx, sys->win);
	mlx_destroy_display(sys->mlx);
	mlx_loop_end(sys->mlx);
	free(sys->mlx);
	system_exit(sys, 0);
	return (0);
}
