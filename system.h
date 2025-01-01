/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:09 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/01 17:59:00 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <X11/X.h>
# include <X11/Xutil.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define E_ALLOCATE -1
# define E_MLX_INIT -2
# define E_WINDOW_CREATE -3
# define E_INVALID_INPUT -4

# define ERRMSG "PLEASE TYPE\n\t* mandelbrot\n\t* julia\n\t* burningship\n"

# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 1000
# define DEFLT_ITER 10

# define MANDELBROT 0
# define JULIA 1
# define BURNINGSHIP 2

typedef struct s_simg
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_simg;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_screen
{
	double		width;
	double		height;
	t_complex	base;
}				t_screen;

typedef struct s_sys
{
	void		*mlx;
	void		*win;
	t_simg		img;
	int			type;
	t_complex	coef;
	t_screen	screen;
	int			iter[SCREEN_HEIGHT][SCREEN_WIDTH];
	t_complex	val[SCREEN_HEIGHT][SCREEN_WIDTH];
	int			sup_iteri;
}				t_sys;

t_sys			*system_init(char *arg);
void			system_exit(t_sys *sys, int status);

void			calculate(t_sys *sys);

#endif