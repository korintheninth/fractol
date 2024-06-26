/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:13:39 by emamati           #+#    #+#             */
/*   Updated: 2024/06/26 18:49:54 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_julia(t_imaginary ir, t_vars *vars, int x, int y)
{
	int			i;
	t_imaginary	num;

	num.a = map(x, WIDTH, -2.0, 2.0) * vars->zoom + vars->x;
	num.b = map(y, HEIGHT, -2.0, 2.0) * vars->zoom + vars->y;
	num.ca = num.a;
	num.cb = num.b;
	i = 0;
	while (i < ITER)
	{
		num.aa = num.a * num.a;
		num.bb = num.b * num.b;
		num.ab2 = num.a * num.b * 2;
		num.a = num.aa - num.bb + ir.a;
		num.b = num.ab2 + ir.b;
		if (num.a * num.a + num.b * num.b > 4)
			return (i);
		i++;
	}
	return (i);
}

int	calc_tricorn(t_vars *vars, int x, int y)
{
	int			i;
	t_imaginary	num;

	num.a = map(x, WIDTH, -2.0, 2.0) * vars->zoom + vars->x;
	num.b = map(y, HEIGHT, -2.0, 2.0) * vars->zoom + vars->y;
	num.ca = num.a;
	num.cb = -num.b;
	i = 0;
	while (i < ITER)
	{
		num.aa = num.a * num.a;
		num.bb = num.b * num.b;
		num.ab2 = num.a * -num.b * 2;
		num.a = num.aa - num.bb + num.ca;
		num.b = num.ab2 - num.cb;
		i++;
		if (num.a * num.a + num.b * num.b > 4)
			return (i);
	}
	return (i);
}

int	calc_mandelbroth(t_vars *vars, int x, int y)
{
	int			i;
	t_imaginary	num;

	num.a = map(x, WIDTH, -2.0, 2.0) * vars->zoom + vars->x;
	num.b = map(y, HEIGHT, -2.0, 2.0) * vars->zoom + vars->y;
	num.ca = num.a;
	num.cb = num.b;
	i = 0;
	while (i < ITER)
	{
		num.aa = num.a * num.a;
		num.bb = num.b * num.b;
		num.ab2 = num.a * num.b * 2;
		num.a = num.aa - num.bb + num.ca;
		num.b = num.ab2 + num.cb;
		i++;
		if (num.a * num.a + num.b * num.b > 4)
			return (i);
	}
	return (i);
}
