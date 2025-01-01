#include "../minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_xvar
{
	void	*mlx;
	void	*win;
}			t_xvar;

#define ESC 0xff1b

typedef struct s_info
{
	void	*mlx;
	void	*win;
	void	*img;
}			t_info;

int	event_handler(int key, void *v_info)
{
	t_info	*info;

	info = v_info;
	printf("key  %x\n", key);
	if (key == ESC)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_info	info;

	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, 1000, 1000, "Hello World");
	mlx_hook(info.win, KeyPress, KeyPressMask, event_handler, info.mlx);
	// mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(info.mlx);
}
