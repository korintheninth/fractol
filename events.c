#include "fractol.h"


int key_hook(int keycode, t_vars *vars) {
	t_params param;

	param = vars->param;
    if (keycode == ESC_KEY)
		close_window(vars);
	if (keycode == UP)
		vars->y -= 0.1 * vars->zoom;
	if (keycode == DOWN)
		vars->y += 0.1 * vars->zoom;
	if (keycode == RIGHT)
		vars->x += 0.1 * vars->zoom;
	if (keycode == LEFT)
		vars->x -= 0.1 * vars->zoom;
	if (keycode == KEY_J)
		vars->zoom *= 1.3;
	if (keycode == KEY_K)
		vars->zoom /= 1.3;
	display_fract(vars, param);
    return (0);
}

int mouse_hook(int button, int x, int y, t_vars *vars) {
    double mouse_x;
    double mouse_y;
    double new_zoom;

    mouse_x = map(x, 0, WIDTH, -2.0, 2.0) * vars->zoom + vars->x;
    mouse_y = map(y, 0, HEIGHT, 2.0, -2.0) * vars->zoom + vars->y;
    if (button == 4)
        new_zoom = vars->zoom * 1.3;
    else if (button == 5)
        new_zoom = vars->zoom / 1.3;
    else
        return 0;
    vars->x = mouse_x - (map(x, 0, WIDTH, -2.0, 2.0) * new_zoom);
    vars->y = mouse_y - (map(y, 0, HEIGHT, 2.0, -2.0) * new_zoom);
    vars->zoom = new_zoom;
    display_fract(vars, vars->param);
    return 0;
}
