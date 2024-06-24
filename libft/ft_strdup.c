/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:50:00 by emamati           #+#    #+#             */
/*   Updated: 2023/12/07 12:12:04 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	void	*dest;

	len = ft_strlen(str) + 1;
	dest = malloc(len);
	if (dest == NULL)
		return (NULL);
	return ((char *)ft_memcpy(dest, str, len));
}
