/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:10:20 by emamati           #+#    #+#             */
/*   Updated: 2023/12/09 02:00:18 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**clear(char **ptr)
{
	char	**original_ptr;

	original_ptr = ptr;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(original_ptr);
	return (0);
}

int	word_count(const char *str, const char c)
{
	int	i;
	int	word_start;
	int	count;

	word_start = 0;
	count = 0;
	word_start = 1;
	i = 0;
	while (str[i])
	{
		if (word_start && str[i] != c)
		{
			count++;
			word_start = 0;
			i++;
		}
		else if (str[i] == c && word_start == 0)
		{
			word_start = 1;
			i++;
		}
		else
			i++;
	}
	return (count);
}

int	get_len(const char *s, int i, const char c)
{
	int	len;

	len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**insert(const char *s, const char c, char **dest, int count)
{
	int	cur;
	int	len;
	int	i;
	int	index;

	i = 0;
	cur = 0;
	while (cur < count)
	{
		len = get_len(s, i, c);
		dest[cur] = (char *)malloc((len + 1) * sizeof(char));
		if (!dest[cur] && (clear(dest), 1))
			return (NULL);
		while (s[i] && s[i] == c)
			i++;
		index = 0;
		while (s[i] != c && s[i])
			dest[cur][index++] = s[i++];
		dest[cur++][index] = '\0';
	}
	return (dest);
}

char	**ft_split(const char *s, const char c)
{
	int		count;
	char	**dest;

	count = word_count(s, c);
	dest = (char **)malloc((count + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	dest = insert(s, c, dest, count);
	dest[count] = 0;
	return (dest);
}
