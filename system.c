#include "system.h"


void system_exit(t_sys *sys,int status)
{
	free(sys);
	exit(status);
}



t_sys *system_init()
{
    t_sys *sys;

    sys = malloc(sizeof(t_sys));
    if (!sys)
        system_exit(NULL, E_ALLOCATE);
    sys->mlx = mlx_init();
    if (!sys->mlx)
        system_exit(NULL, E_ALLOCATE);
    sys->win = mlx_new_window(sys->mlx, SCREEN_HEIGHT, SCREEN_WIDTH, "FRACTOL");
    if (!sys->win)
        system_exit(NULL, E_ALLOCATE);
    sys->img.img = mlx_new_image(sys->mlx, SCREEN_HEIGHT, SCREEN_WIDTH);
    if (!sys->img.img)
        system_exit(NULL, E_ALLOCATE);
    sys->img.addr = mlx_get_data_addr(sys->img.img, &sys->img.bits_per_pixel, &sys->img.line_length, &sys->img.endian);

}

