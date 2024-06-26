/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:51:46 by emamati           #+#    #+#             */
/*   Updated: 2024/06/26 19:33:14 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	checker(char *str)
{
	int	dot_count;

	if (*str == '.' && *(str + 1) == 0)
		return (0);
	dot_count = 0;
	while (*str)
	{
		if (ft_isalpha(*str))
			return (0);
		if (*str == '.')
			dot_count++;
		str++;
	}
	if (dot_count > 1)
		return (0);
	return (1);
}

void	get_colors(t_params *params, char **argv)
{
	int	i;

	params->red = 3;
	params->green = 6;
	params->blue = 5;
	if (params->fract == 1)
		i = 4;
	else
		i = 2;
	while (argv[i])
	{
		if (!ft_strcmp("red", argv[i]) && argv[i + 1] && checker(argv[i + 1]))
			params->red = ft_atoi(argv[i++ + 1]);
		else if (!ft_strcmp("blue", argv[i]) && argv[i + 1]
			&& checker(argv[i + 1]))
			params->blue = ft_atoi(argv[i++ + 1]);
		else if (!ft_strcmp("green", argv[i]) && argv[i + 1]
			&& checker(argv[i + 1]))
			params->green = ft_atoi(argv[i++ + 1]);
		else
			params->fract = -1;
		i++;
	}
}

t_params	parser(int argc, char **argv)
{
	t_params	params;

	if (argc < 2)
	{
		params.fract = -1;
		return (params);
	}
	params.fract = -1;
	params.real = 0;
	params.imag = 0;
	if (!ft_strcmp("mandelbroth", argv[1]) || !ft_strcmp("M", argv[1]))
		params.fract = 0;
	else if ((!ft_strcmp("julia", argv[1]) || !ft_strcmp("J", argv[1]))
		&& argc >= 4)
	{
		params.fract = 1;
		params.real = ft_atof(argv[2]);
		params.imag = ft_atof(argv[3]);
		if (!checker(argv[2]) || !checker(argv[3]))
			params.fract = -1;
	}
	else if (!ft_strcmp("tricorn", argv[1]) || !ft_strcmp("T", argv[1]))
		params.fract = 2;
	get_colors(&params, argv);
	return (params);
}

int	main(int argc, char **argv)
{
	t_params	param;
	t_vars		vars;
	t_image		img;

	param = parser(argc, argv);
	if (param.fract != -1)
	{
		vars.param = param;
		set_vars(&vars, &img);
		if (param.fract == 0)
			fractal_mandelbroth(&vars.screen, &vars);
		else if (param.fract == 1)
			fractal_julia(&vars.screen, param.real, param.imag, &vars);
		else if (param.fract == 2)
			fractal_tricorn(&vars.screen, &vars);
		set_mlx(&vars);
	}
	else
		prterr();
	return (0);
}
