#ifndef FRACTOL_H
#define FRACTOL_H
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 900
#define HEIGHT 900
#define ITER 600
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

double map(double var, double min, double max, double map_min, double map_max);
int	ft_strcmp(const char *str1, const char *str2);
float ft_atof(const char *str);
int zigzag_map(int var, int min, int max);
void fractal_mandelbroth(t_image *img, double min, double max, int iter, double shiftx, double shifty, t_vars *vars);
void fractal_tricorn(t_image *img, double min, double max, int iter, double shiftx, double shifty, t_vars *vars);
void fractal_julia(t_image *img, double real, double imag, double min, double max, int iter, double shiftx, double shifty, t_vars *vars);
void refresh(t_image *img, t_image *screen, t_vars *vars);
void put_pixel(t_image *img, int x, int y, int color);
void display_fract(t_vars *vars, t_params param);
int close_window(t_vars *vars);
int key_hook(int keycode, t_vars *vars);
int mouse_hook(int button, int x, int y, t_vars *vars);
void refresh(t_image *img, t_image *screen, t_vars *vars);

#endif
