/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:02:54 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:02:55 by jojaen-m         ###   ########.fr       */
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
