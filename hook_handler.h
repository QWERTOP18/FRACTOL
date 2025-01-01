#ifndef FRACTOL_HOOK
# define FRACTOL_HOOK

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

int	exit_handler(t_sys *sys);
int	key_handler(int key, t_sys *sys);
int	mouse_handler(int button, int x, int y, t_sys *sys);
int	loop_handler(t_sys *sys);

#endif