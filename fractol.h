/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:49:04 by emamati           #+#    #+#             */
/*   Updated: 2024/06/26 19:58:28 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 900
# define HEIGHT 900
# define ITER 60
# define ESC_KEY 53
# define RIGHT 124
# define LEFT 123
# define UP 125
# define DOWN 126
# define KEY_J 38
# define KEY_K 40

typedef struct rgbc
{
	int			red;
	int			blue;
	int			green;
	int			color;
}				t_rgbc;

typedef struct params
{
	int			fract;
	float		real;
	float		imag;
	int			iter;
	int			red;
	int			green;
	int			blue;
}				t_params;

typedef struct imaginary
{
	double		a;
	double		b;
	double		ca;
	double		cb;
	double		aa;
	double		bb;
	double		ab2;
}				t_imaginary;

typedef struct image
{
	void		*img;
	char		*addr;
	int			bbp;
	int			ll;
	int			endian;
}				t_image;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	double		x;
	double		y;
	t_image		img;
	t_image		screen;
	double		zoom;
	t_params	param;
}				t_vars;

double			map(double var, double max, double map_min,
					double map_max);
int				ft_strcmp(const char *str1, const char *str2);
float			ft_atof(const char *str);
int				zigzag_map(int var, int min, int max);
void			fractal_mandelbroth(t_image *img, t_vars *vars);
void			fractal_tricorn(t_image *img, t_vars *vars);
void			fractal_julia(t_image *img, double real,
					double imag, t_vars *vars);
void			refresh(t_image *img, t_image *screen, t_vars *vars);
void			put_pixel(t_image *img, int x, int y, int color);
void			display_fract(t_vars *vars, t_params param);
int				close_window(t_vars *vars);
int				key_hook(int keycode, t_vars *vars);
int				mouse_hook(int button, int x, int y, t_vars *vars);
void			refresh(t_image *img, t_image *screen, t_vars *vars);
void			set_vars(t_vars *vars, t_image *img);
void			prterr(void);
void			set_mlx(t_vars *vars);
int				calc_julia(t_imaginary ir, t_vars *vars, int x, int y);
int				calc_tricorn(t_vars *vars, int x, int y);
int				calc_mandelbroth(t_vars *vars, int x, int y);

#endif
