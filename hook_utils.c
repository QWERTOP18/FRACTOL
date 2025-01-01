#include "hook_handler.h"

void	zoom_screen(t_sys *sys, double ratio, int x, int y)
{
	t_screen	screen;
	t_complex	center;

	screen = sys->screen;
	center.re = (double)x / SCREEN_WIDTH / screen.width + screen.base.re;
	center.im = (double)y / SCREEN_HEIGHT / screen.height + screen.base.im;
	screen.base.re = center.re + (screen.base.re - center.re) * ratio;
	screen.base.im = center.im + (screen.base.im - center.im) * ratio;
	screen.width *= ratio;
	screen.height *= ratio;
	// sys.screen=screen;
}

void	pan_screen(t_sys *sys, int id)
{
	static double	dy[4] = {0, -1, 0, 1};
	static double	dx[4] = {-1, 0, 1, 0};
	t_screen		screen;

	screen = sys->screen;
	screen.base.re += dy[id] * screen.width * DELTA;
	screen.base.im += dx[id] * screen.height * DELTA;
}

void	modify_coefficient(t_sys *sys, int id)
{
	static double dy[4] = {-1, 0, 1, 0};
	static double dx[4] = {0, -1, 0, 1};

	sys->coef.im += dy[id];
	sys->coef.re += dx[id];
}