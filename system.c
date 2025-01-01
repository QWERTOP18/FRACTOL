/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:03:21 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/01 14:56:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

int		identify_arg(char *arg, t_sys *sys);
void	system_exit(t_sys *sys, int status)
{
	if (status == E_INVALID_INPUT)
		ft_putendl_fd(ERRMSG, 2);
	free(sys);
	exit(status);
}

t_sys	*system_init(char *arg)
{
	t_sys	*sys;

	sys = malloc(sizeof(t_sys));
	if (!sys)
		system_exit(NULL, E_ALLOCATE);
	sys->type = identify_arg(arg, sys);
	sys->sup_iteri = DEFLT_ITER;
	ft_memset(sys->iter,0,sizeof(sys->iter));
	sys->mlx = mlx_init();
	if (!sys->mlx)
		system_exit(NULL, E_MLX_INIT);
	sys->win = mlx_new_window(sys->mlx, SCREEN_HEIGHT, SCREEN_WIDTH, "FRACTOL");
	if (!sys->win)
		system_exit(NULL, E_MLX_INIT);
	sys->img.img = mlx_new_image(sys->mlx, SCREEN_HEIGHT, SCREEN_WIDTH);
	if (!sys->img.img)
		system_exit(NULL, E_ALLOCATE);
	sys->img.addr = mlx_get_data_addr(sys->img.img, &sys->img.bits_per_pixel,
			&sys->img.line_length, &sys->img.endian);
	return (sys);
}

int	identify_arg(char *arg, t_sys *sys)
{
	if (ft_strncmp(arg, "mandelbrot", ft_strlen(arg)) == 0)
		return (MANDELBROT);
	if (ft_strncmp(arg, "julia", ft_strlen(arg)) == 0)
		return (JULIA);
	if (ft_strncmp(arg, "burningship", ft_strlen(arg)) == 0)
		return (BURNINGSHIP);

	ft_putendl_fd(ERRMSG, 2);

	system_exit(sys, E_INVALID_INPUT);
	return (0);
}