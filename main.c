/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:02:51 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/01 14:57:05 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_handler.h"
#include "system.h"

//なぜintなのか
int	loop_handler(t_sys *sys)
{
	// update(sys);
	// int	mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,t_img *img,
	// 		int x,int y)
	// mlx_put_image_to_window(sys->mlx, sys->win, sys->img.img, 0, 0);
	return (0);
}

void	setup_hook(t_sys *sys)
{
	mlx_hook(sys->win, KeyPress, KeyPressMask, key_handler, sys);
	mlx_hook(sys->win, ClientMessage, StructureNotifyMask, exit_handler, sys);
	mlx_mouse_hook(sys->win, mouse_handler, sys);
	mlx_loop_hook(sys->mlx, loop_handler, sys);
}
// REIZEMASKって画面サイズを変えるのかな

int	main(int argc, char **argv)
{
	t_sys *sys;
	if (argc != 2)
		system_exit(NULL, E_INVALID_INPUT);
	sys = system_init(argv[1]);
	setup_hook(sys);

	mlx_loop(sys->mlx);
}