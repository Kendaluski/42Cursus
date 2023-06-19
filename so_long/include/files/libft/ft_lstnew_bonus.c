/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:30:16 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 21:38:15 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*newlist;

	newlist = malloc(sizeof(struct s_list));
	if (!newlist)
		return (0);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
