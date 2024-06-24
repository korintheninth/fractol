/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:11:15 by emamati           #+#    #+#             */
/*   Updated: 2023/12/07 20:04:49 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	endsize;
	size_t	i;

	i = 0;
	endsize = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		endsize = ft_strlen(s) - start;
	if (endsize > len)
		endsize = len;
	dest = (char *)malloc(sizeof(char) * (endsize + 1));
	if (!dest)
		return (NULL);
	s = s + start;
	dest[endsize] = '\0';
	while (i < endsize && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}
