/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:26:29 by emamati           #+#    #+#             */
/*   Updated: 2023/12/12 13:26:32 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_link;

	new_link = (t_list *)malloc(sizeof(t_list));
	if (!new_link)
		return (NULL);
	new_link->content = content;
	new_link->next = NULL;
	return (new_link);
}
