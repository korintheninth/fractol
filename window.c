/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:51:39 by emamati           #+#    #+#             */
/*   Updated: 2024/06/26 18:42:49 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_image(vars->mlx, vars->screen.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	y = HEIGHT - y;
	dst = img->addr + (y * img->ll + x * (img->bbp / 8));
	*(unsigned int *)dst = color;
}

void	display_fract(t_vars *vars, t_params param)
{
	if (param.fract == 0)
		fractal_mandelbroth(&vars->img, vars);
	else if (param.fract == 1)
		fractal_julia(&vars->img, param.real, param.imag, vars);
	else if (param.fract == 2)
		fractal_tricorn(&vars->img, vars);
	refresh(&vars->img, &vars->screen, vars);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->screen.img, 0, 0);
}

void	refresh(t_image *img, t_image *screen, t_vars *vars)
{
	ft_memcpy(screen->addr, img->addr, WIDTH * HEIGHT * 4);
	ft_bzero(img->addr, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(vars->mlx, vars->win, screen->img, 0, 0);
}

void	set_vars(t_vars *vars, t_image *img)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fractol");
	vars->x = 0;
	vars->y = 0;
	vars->zoom = 1.0;
	img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bbp, &img->ll, &img->endian);
	vars->img = *img;
	vars->screen.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->screen.addr = mlx_get_data_addr(vars->screen.img, &vars->screen.bbp,
			&vars->screen.ll, &vars->screen.endian);
}
