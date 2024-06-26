/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:51:49 by emamati           #+#    #+#             */
/*   Updated: 2024/06/26 18:51:44 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color(int i, t_params param)
{
	t_rgbc	rgbc;

	rgbc.red = zigzag_map(i * param.red, 0, 255);
	rgbc.green = zigzag_map(i * param.green, 0, 255);
	rgbc.blue = zigzag_map(i * param.blue, 0, 255);
	rgbc.color = 0x00000000 + (rgbc.red * 0x00010000) + (rgbc.green
			* 0x00000100) + (rgbc.blue * 0x00000001);
	return (rgbc.color);
}

void	fractal_mandelbroth(t_image *img, t_vars *vars)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			i = calc_mandelbroth(vars, x, y);
			if (i != ITER)
				put_pixel(img, x, y, color(i, vars->param));
			y++;
		}
		x++;
	}
}

void	fractal_tricorn(t_image *img, t_vars *vars)
{
	double		x;
	double		y;
	int			i;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			i = calc_tricorn(vars, x, y);
			if (i != ITER)
				put_pixel(img, x, y, color(i, vars->param));
			y++;
		}
		x++;
	}
}

void	fractal_julia(t_image *img, double real, double imag, t_vars *vars)
{
	int			x;
	int			y;
	int			i;
	t_imaginary	ir;

	ir.a = real;
	ir.b = imag;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			i = calc_julia(ir, vars, x, y);
			if (i != ITER)
				put_pixel(img, x, y, color(i, vars->param));
			y++;
		}
		x++;
	}
}
