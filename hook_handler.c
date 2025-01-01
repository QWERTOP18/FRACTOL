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


void zoom_screen(t_sys * sys, double ratio ,int x, int y)
{
	t_screen screen = sys->screen;
	t_complex center;

	center.re = (double)x / WIDTH / screen.width + screen.base.re;
	center.im = (double)y / HEIGHT / screen.height + screen.base.im;

	screen->base.re = center_re + (screen->base.re - center_re) * ratio;
    screen->base.im = center_im + (screen->base.im - center_im) * ratio;

    screen->width *= ratio;
    screen->height *= ratio;

	//sys->screen=screen;
}

void pan_screen(t_sys * sys, int id)
{
	static double dy[4] = {0, -1, 0, 1};
	static double dx[4] = {-1, 0, 1, 0};

	t_screen screen = sys->screen;
    screen->base.re += dy[id] * screen.width * DELTA;
	screen->base.im += dx[id] * screen.height * DELTA;
}





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
	return (0);
}

int	exit_handler(t_sys *sys)
{
	mlx_destroy_window(sys->mlx, sys->win);
	system_exit(sys, 0);
	return (0);
}
