/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:51:42 by emamati           #+#    #+#             */
/*   Updated: 2024/06/26 19:54:27 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double var, double max, double map_min, double map_max)
{
	double	scale;
	double	ret;

	scale = (map_max - map_min) / (max);
	ret = (var) * scale + map_min;
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

float	ft_atof(const char *str)
{
	float	nb;
	float	fraction;
	float	divisor;
	int		mult;

	nb = 0;
	fraction = 0;
	divisor = 10;
	mult = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			mult = -1;
	while (*str && *str >= '0' && *str <= '9')
		nb = nb * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		fraction += (*str++ - '0') / divisor;
		divisor *= 10;
	}
	return (mult * (nb + fraction));
}

int	zigzag_map(int var, int min, int max)
{
	int	range;
	int	cycles;
	int	rem;

	range = max - min;
	cycles = (var - min) / range;
	rem = (var - min) % range;
	if (cycles % 2 == 0)
		return (min + rem);
	else
		return (max - rem);
}

void	prterr(void)
{
	write(2, "\nUsage: ./fractol mandelbroth/M/julia/J/tricorn/T.\n", 51);
	write(2, "For julia enter real and imaginary parts after.\n", 48);
	write(2, "You can change the rgb steps by $color $step_int\n\n", 50);
}
