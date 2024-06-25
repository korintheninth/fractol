#include "fractol.h"

int color(int i, t_params param)
{
	t_rgbc rgbc;
	rgbc.red = zigzag_map(i * param.red, 0, 255);
	rgbc.green = zigzag_map(i * param.green, 0, 255);
	rgbc.blue = zigzag_map(i * param.blue, 0, 255);
	rgbc.color = 0x00000000 + (rgbc.red * 0x00010000) + (rgbc.green * 0x00000100) +  (rgbc.blue * 0x00000001) ;
	return (rgbc.color);
}

void fractal_mandelbroth(t_image *img, double min, double max, int iter, double shiftx, double shifty, t_vars *vars){
	int x = 0;
	int y = 0;
	t_imaginary num;
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
			if (i != iter)
				put_pixel(img, x, y, color(i, vars->param));
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
			if (i != iter)
				put_pixel(img, x, y, color(i, vars->param));
		y++;
	}
	x++;
	}
}

void fractal_julia(t_image *img, double real, double imag, double min, double max, int iter, double shiftx, double shifty, t_vars *vars){
	int x;
	t_imaginary num;
	int y;
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
			if (i != iter)
				put_pixel(img, x, y, color(i, vars->param));
		y++;
	}
	x++;
	}
}

