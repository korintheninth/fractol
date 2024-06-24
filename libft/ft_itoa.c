/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:33:01 by emamati           #+#    #+#             */
/*   Updated: 2023/12/09 03:20:38 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_length(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len = 1;
	}
	while (n && ++len)
		n = n / 10;
	return (len);
}

char	*ft_itoa(int num)
{
	int		len;
	char	*dest;
	long	n;

	n = num;
	len = get_length(n);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	if (n == 0)
		dest[0] = '0';
	if (n < 0)
	{
		dest[0] = '-';
		n *= -1;
	}
	dest[len--] = '\0';
	while (n)
	{
		dest[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (dest);
}
