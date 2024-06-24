/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:34:56 by emamati           #+#    #+#             */
/*   Updated: 2023/12/07 14:50:03 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	char	*str;
	char	*to_find;
	int		i;

	str = (char *)big;
	to_find = (char *)small;
	if (*to_find == '\0')
		return (str);
	while (*str && len)
	{
		i = 0;
		if (*str == to_find[0])
		{
			while (str[i] == to_find[i] && to_find[i] && len - i)
				i++;
			if (to_find[i] == '\0')
				return (str);
		}
		str++;
		len--;
	}
	return (0);
}
