#include "fractol.h"


int close_window(t_vars *vars) {
	mlx_loop_end(vars->mlx);
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_image(vars->mlx, vars->screen.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

void put_pixel(t_image *img, int x, int y, int color){
	char *dst;

	y = HEIGHT - y; 
	dst = img->addr + (y * img->ll + x * (img-> bbp / 8));
	*(unsigned int*)dst = color;
}

void display_fract(t_vars *vars, t_params param) {
    if (param.fract == 0) 
        fractal_mandelbroth(&vars->img, -2.0, 2.0, ITER, vars->x, vars->y, vars);
    else if (param.fract == 1)
        fractal_julia(&vars->img, param.real, param.imag, -2.0, 2.0, ITER, vars->x, vars->y, vars);
    else if (param.fract == 2)
        fractal_tricorn(&vars->img, -2.0, 2.0, ITER, vars->x, vars->y, vars);
    refresh(&vars->img, &vars->screen, vars);
    mlx_clear_window(vars->mlx, vars->win);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->screen.img, 0, 0);
}

void refresh(t_image *img, t_image *screen, t_vars *vars){
	ft_memcpy(screen->addr, img->addr, WIDTH * HEIGHT * 4);
	ft_bzero(img->addr, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(vars->mlx, vars->win, screen->img, 0, 0);
}
