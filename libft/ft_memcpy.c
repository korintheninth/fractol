/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:33:40 by emamati           #+#    #+#             */
/*   Updated: 2023/12/12 14:43:55 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	if (!dest && !src)
		return (NULL);
	ptr2 = src;
	ptr1 = dest;
	if (dest != src)
	{
		while (n--)
			*ptr1++ = *ptr2++;
	}
	return (dest);
}
