/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamati <emamati@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 06:51:58 by emamati           #+#    #+#             */
/*   Updated: 2023/12/12 11:20:53 by emamati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_link;
	t_list	*new_list_begin;

	if (!lst || !f || !del)
		return (NULL);
	new_list_begin = NULL;
	while (lst)
	{
		new_link = ft_lstnew(f(lst->content));
		if (!new_link)
			ft_lstdelone(new_link, del);
		ft_lstadd_back(&new_list_begin, new_link);
		lst = lst->next;
	}
	return (new_list_begin);
}
