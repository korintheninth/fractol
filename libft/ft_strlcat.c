/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:05:02 by emamati           #+#    #+#             */
/*   Updated: 2023/12/08 18:04:51 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	sizedest;
	size_t	sizesrc;
	size_t	i;
	int		j;

	sizedest = ft_strlen(dest);
	sizesrc = ft_strlen(src);
	if (!dest || size == 0)
		return (sizesrc);
	if (sizedest >= size)
		return (size + sizesrc);
	else
	{
		j = 0;
		i = sizedest;
		while (i < size - 1 && src[j])
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
		return (sizedest + sizesrc);
	}
}
