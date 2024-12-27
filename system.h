#ifndef SYSTEM_H
#define SYSTEM_H

#include "mlx.h"
#include "mlx_int.h"
#include <math.h>
#include <fcntl.h>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <X11/X.h>
// #include <X11/Xutil.h>
#include <stdlib.h>
#include <unistd.h>

#define E_ALLOCATE -1




#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000



typedef struct s_back_screen
{
    void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
} t_back_screen;
// typedef struct s_image
// {
// 	void	*img_ptr;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_image;


typedef struct	s_sys {
	void				*mlx;
	void				*win;
	t_back_screen				img;
	//      t_fractal_drawer	fractal_drawer;
	
	

} t_sys;





t_sys *system_init();
void system_exit(t_sys *sys,int status);

#endif