#include "../minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_xvar
{
	void	*mlx;
	void	*win;
}			t_xvar;

#define ESC 0xFF1B

typedef struct s_info
{
	void	*mlx;
	void	*win;
	void	*img;
}			t_info;

//

int	exit_handler(void *v_info)
{
	t_info	*info;

	info = (t_info *)v_info;
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}

int	key_handler(int key, void *v_info)
{
	t_info	*info;

	info = (t_info *)v_info;
	printf("key  %d\n", key);
	if (key == ESC)
	{
		// mlx_destroy_image(info->mlx, info->win);
		exit_handler(info);
	}
	if (isalnum(key))
		printf("char %c\n", key);
	return (0);
}

int	main(void)
{
	t_info	info;

	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, 1000, 1000, "Hello World");
	mlx_hook(info.win, KeyPress, KeyPressMask, key_handler, &info);
	mlx_hook(info.win, ClientMessage, StructureNotifyMask, exit_handler, &info);
	mlx_loop(info.mlx);
}
