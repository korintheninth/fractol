#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 900
#define HEIGHT 900
#define ITER 60
#define ESC_KEY 65307
#define RIGHT 65363
#define LEFT 65361
#define UP 65364
#define DOWN 65362
#define KEY_J 106
#define KEY_K 107

typedef struct rgbc{
	int red;
	int blue;
	int green;
	int color;
} t_rgbc;

typedef struct params{
	int fract;
	float real;
	float imag;
	int iter;
	int red;
	int green;
	int blue;
}t_params;

typedef struct imaginary{
	double a;
	double b;
	double ca;
	double cb;
	double aa;
	double bb;
	double ab2;
}	t_imaginary;

typedef struct image{
	void *img;
	char *addr;
	int bbp;
	int ll;
	int endian;
}	t_image;

typedef struct s_vars {
    void *mlx;
    void *win;
	double x;
	double y;
	t_image img;
	t_image screen;
	double zoom;
	t_params param;
}              t_vars;

void fractal_mandelbroth(t_image *img, double min, double max, int iter, double shiftx, double shifty, t_vars *vars);
void fractal_tricorn(t_image *img, double min, double max, int iter, double shiftx, double shifty, t_vars *vars);
void fractal_julia(t_image *img, double real, double imag, double min, double max, int iter, double shiftx, double shifty, t_vars *vars);
void refresh(t_image *img, t_image *screen, t_vars *vars);

double map(double var, double min, double max, double map_min, double map_max){
	double scale = (map_max - map_min)/(max - min);
	double ret = (var - min) * scale + map_min;
	return (ret);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
	}
	return (0);
}

float ft_atof(const char *str)
{
	int	i;
	int	mult;
	float	nb;
	float	point;
	float	pointlen;

	mult = 1;
	nb = 0;
	i = 0;
	point = 0;
	pointlen = 10;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] && str[i] != '.' && (str[i] <= '9' && str[i] >= '0'))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		point += (str[i] - '0') / pointlen;
		i++;
		pointlen *= 10;
	}
	nb += point;
	return (point);
}

int zigzag_map(int var, int min, int max){
	int range = max - min;
	int cycles = (var - min) / range;
	int rem = (var - min) % range;
	if (cycles % 2 == 0)
		return (min + rem);
	else
		return (max - rem);
}

t_params parser(int argc, char **argv){
	t_params params;
	int i;

	params.fract = -1;
	params.real = 0;
	params.imag = 0;
	params.red = 3;
	params.green = 6;
	params.blue = 5;
	if (!ft_strcmp("mandelbroth", argv[1]) || !ft_strcmp("M", argv[1]))
		params.fract = 0;
	else if ((!ft_strcmp("julia", argv[1]) || !ft_strcmp("J", argv[1])) && argc > 2)
	{
		params.fract = 1;
		params.real = ft_atof(argv[2]);
		params.imag = ft_atof(argv[3]);
		i = 0;
		while (argv[2][i])
			if (!ft_isdigit(argv[2][i++]))
				params.fract = -1;
		i = 0;
		while (argv[3][i])
			if (!ft_isdigit(argv[3][i++]))
				params.fract = -1;
	}
	else if (!ft_strcmp("tricorn", argv[1]) || !ft_strcmp("T", argv[1]))
		params.fract = 2;
	if (params.fract == 1)
		i = 4;
	else
		i = 2;
	while (argv[i])
	{
		if (!ft_strcmp("red", argv[i]) && argv[i + 1])
			params.red = ft_atoi(argv[i + 1]);
		else if (!ft_strcmp("blue", argv[i]) && argv[i + 1])
			params.blue = ft_atoi(argv[i + 1]);
		else if (!ft_strcmp("green", argv[i]) && argv[i + 1])
			params.green = ft_atoi(argv[i + 1]);
		else 
			params.fract = -1;
		i++;
	}
	return (params);
}

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

	mouse_x = map(x, 0, WIDTH, -2.0, 2.0) * vars->zoom + vars->x;
	mouse_y = map(y, 0, HEIGHT, -2.0, 2.0) * vars->zoom + vars->y;
	if (button == 4)
    	vars->zoom *= 1.3;
	else if (button == 5)
		vars->zoom /= 1.3;
	vars->x = mouse_x - (map(x, 0, WIDTH, -2.0, 2.0) * vars->zoom);
	vars->y = mouse_y - (map(y, 0, HEIGHT, -2.0, 2.0) * vars->zoom);
	display_fract(vars, vars->param);
	return 0;
}

void put_pixel(t_image *img, int x, int y, int color){
	char *dst;

	y = HEIGHT - y; 
	dst = img->addr + (y * img->ll + x * (img-> bbp / 8));
	*(unsigned int*)dst = color;
}

void refresh(t_image *img, t_image *screen, t_vars *vars){
	ft_memcpy(screen->addr, img->addr, WIDTH * HEIGHT * 4);
	ft_bzero(img->addr, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(vars->mlx, vars->win, screen->img, 0, 0);
}

void fractal_mandelbroth(t_image *img, double min, double max, int iter, double shiftx, double shifty, t_vars *vars){
	int x = 0;
	int y = 0;
	t_imaginary num;
	t_rgbc rgbc;
	int i;
	while (x < WIDTH){
		y = 0;
		while (y <= HEIGHT){
			num.a = map(x, 0.0, WIDTH, min, max) * vars->zoom + shiftx;
			num.b = map(y, 0.0, HEIGHT, min, max) * vars->zoom + shifty;
			num.ca = num.a;
			num.cb = num.b;
			i = 0;
			while (i < iter){
				num.aa = num.a * num.a;
				num.bb = num.b * num.b;
				num.ab2 = num.a * num.b * 2;
				num.a = num.aa - num.bb + num.ca;
				num.b = num.ab2 + num.cb;
				i++;
				if (num.a * num.a + num.b * num.b > 4)
					break;
			}
			if (i != iter){
				rgbc.red = zigzag_map(i * vars->param.red, 0, 255);
				rgbc.green = zigzag_map(i * vars->param.green, 0, 255);
				rgbc.blue = zigzag_map(i * vars->param.blue, 0, 255);
				rgbc.color = 0x00000000 + (rgbc.red * 0x00010000) + (rgbc.green * 0x00000100) +  (rgbc.blue * 0x00000001) ;
				put_pixel(img, x, y, rgbc.color);}
		y++;	
	}
	x++;
	}
}

void fractal_tricorn(t_image *img, double min, double max, int iter, double shiftx, double shifty, t_vars *vars){
	double x = 0;
	double y = 0;
	t_imaginary num;
	int i;
	t_rgbc rgbc;

	while (x < WIDTH){
		y = 0;
		while (y <= HEIGHT){
			num.a = map(x, 0.0, WIDTH, min, max) * vars->zoom + shiftx;
			num.b = map(y, 0.0, HEIGHT, min, max) * vars->zoom + shifty;
			num.ca = num.a;
			num.cb = -num.b;
			i = 0;
			while (i < iter){
				num.aa = num.a * num.a;
				num.bb = num.b * num.b;
				num.ab2 = num.a * -num.b * 2;
				num.a = num.aa - num.bb + num.ca;
				num.b = num.ab2 - num.cb;
				i++;
				if (num.a * num.a + num.b * num.b > 4)
					break;
			}
			if (i != iter){
				rgbc.red = zigzag_map(i * vars->param.red, 0, 255);
				rgbc.green = zigzag_map(i * vars->param.green, 0, 255);
				rgbc.blue = zigzag_map(i * vars->param.blue, 0, 255);
				rgbc.color = 0x00000000 + (rgbc.red * 0x00010000) + (rgbc.green * 0x00000100) +  (rgbc.blue * 0x00000001) ;
				put_pixel(img, x, y, rgbc.color);}
		y++;
	}
	x++;
	}
}

void fractal_julia(t_image *img, double real, double imag, double min, double max, int iter, double shiftx, double shifty, t_vars *vars){
	int x;
	t_imaginary num;
	int y;
	t_rgbc rgbc;
	int i;

	x = 0;
	while (x < WIDTH){
		y = 0;
		while (y <= HEIGHT){
			num.a = map(x, 0.0, WIDTH, min, max) * vars->zoom + shiftx;
			num.b = map(y, 0.0, HEIGHT, min, max) * vars->zoom + shifty;
			num.ca = num.a;
			num.cb = num.b;
			i = 0;
			while (i < iter){
				num.aa = num.a * num.a;
				num.bb = num.b * num.b;
				num.ab2 = num.a * num.b * 2;
				num.a = num.aa - num.bb + real;
				num.b = num.ab2 + imag;
				if (num.a * num.a + num.b * num.b > 4)
					break;
				i++;
			}
			if (i != iter){
				rgbc.red = zigzag_map(i * vars->param.red, 0, 255);
				rgbc.green = zigzag_map(i * vars->param.green, 0, 255);
				rgbc.blue = zigzag_map(i * vars->param.blue, 0, 255);
				rgbc.color = 0x00000000 + (rgbc.red * 0x00010000) + (rgbc.green * 0x00000100) +  (rgbc.blue * 0x00000001) ;
				put_pixel(img, x, y, rgbc.color);}
		y++;
	}
	x++;
	}
}

int main(int argc, char **argv)
{
	t_params param = parser(argc, argv);
    t_vars vars;

	if (param.fract != -1){
		vars.param = param;
    	vars.mlx = mlx_init();
    	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");
		vars.x = 0;
		vars.y = 0;
		vars.zoom = 1.0;
		t_image img;
		img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bbp, &img.ll, &img.endian);
	
		vars.img = img;
		vars.screen.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
		vars.screen.addr = mlx_get_data_addr(vars.screen.img, &vars.screen.bbp, &vars.screen.ll, &vars.screen.endian);
	
		int i = 0;
		if (param.fract == 0)
			fractal_mandelbroth(&vars.screen, -2.0, 2.0, ITER, vars.x, vars.y, &vars);
		else if (param.fract == 1)
			fractal_julia(&vars.screen, param.real, param.imag, -2.0, 2.0, ITER, vars.x, vars.y, &vars);
		else if (param.fract == 2)
			fractal_tricorn(&vars.screen, -2.0, 2.0, ITER, vars.x, vars.y, &vars);
		mlx_put_image_to_window(vars.mlx, vars.win, vars.screen.img, 0, 0);
		mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
		mlx_hook(vars.win, 17, 0, close_window, &vars);
		mlx_mouse_hook(vars.win, mouse_hook, &vars);
    	mlx_loop(vars.mlx);
	}
	else
		printf("Usage: ./fractol mandelbroth/M/julia/J/tricorn/T/newton/N. For julia enter real and imaginary parts after. You can change the rgb steps by $color $step_int");
    return 0;
}
