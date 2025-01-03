/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:13:15 by ymizukam          #+#    #+#             */
/*   Updated: 2025/01/03 17:13:44 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_HANDLER_H
# define HOOK_HANDLER_H

# include "system.h"

# define ESCAPE 0xFF1B
# define LSHIFT 0xFFE1
# define RSHIFT 0xFFE2

# define LEFT 0xFF51
# define UP 0xFF52
# define RIGHT 0xFF53
# define DOWN 0xFF54

# define LEFT_CLICK 1
# define CENTER_CLICK 2
# define RIGHT_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define DELTA 0.01

int		exit_handler(t_sys *sys);
int		key_handler(int key, t_sys *sys);
int		mouse_handler(int button, int x, int y, t_sys *sys);
int		loop_handler(t_sys *sys);

/**** **** **** **** ***** **** **** **** ****/
/**** **** **** **** UTILS **** **** **** ****/
/**** **** **** **** ***** **** **** **** ****/

void	pan_screen(t_sys *sys, int id);
void	zoom_screen(t_sys *sys, double ratio, int x, int y);
void	modify_coefficient(t_sys *sys, int id);
void	modify_color_range(t_sys *sys, int id);

#endif