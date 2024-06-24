/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:07:00 by emamati           #+#    #+#             */
/*   Updated: 2023/12/07 16:39:56 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;
	unsigned char		*lastptr1;
	unsigned char		*lastptr2;

	ptr1 = dest;
	ptr2 = src;
	if (!dest && !src)
		return (NULL);
	if (ptr1 < ptr2)
		while (n--)
			*ptr1++ = *ptr2++;
	else
	{
		lastptr1 = (unsigned char *)ptr1 + (n - 1);
		lastptr2 = (unsigned char *)ptr2 + (n - 1);
		while (n--)
		{
			*lastptr1-- = *lastptr2--;
		}
	}
	return (dest);
}
