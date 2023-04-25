/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:12:36 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/25 14:55:01 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*resl;
	t_list	*first;

	if (!lst)
		return (NULL);
	first = malloc(sizeof(t_list));
	if (!first)
		return (NULL);
	resl = first;
	resl->content = f(lst->content);
	while (lst->next)
	{
		lst = lst->next;
		resl->next = malloc(sizeof(t_list));
		if (!resl->next)
		{
			ft_lstclear(&first, del);
			return (0);
		}
		resl->next->content = f(lst->content);
		resl = resl->next;
	}
	resl->next = NULL;
	return (first);
}
