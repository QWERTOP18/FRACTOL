#ifndef FRACTOL_HOOK
# define FRACTOL_HOOK

# include "system.h"

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ESCAPE 65307
# define SHIFT 65505

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

# define MOUSE_MOVE 6
# define MOUSE_PRESS 4
# define MOUSE_RELEASE 5

# define LEFT_CLICK 1
# define RIGHT_CLICK 3

int	exit_handler(t_sys *sys);
int	key_handler(int key, t_sys *sys);
int	mouse_handler(int button, int x, int y, t_sys *sys);
int	loop_handler(t_sys *sys);

#endif