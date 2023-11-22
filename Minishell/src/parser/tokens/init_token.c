/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:07:14 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/14 21:05:18 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static t_token	*ft_lstnew_mini(char *argv);
static t_token	*ft_lstlast_mini(t_token *lst);
static void		ft_lstadd_back_mini(t_token **lst, t_token *new);

t_token	*ft_init_token(void)
{
	t_token	*list;
	int		i;

	i = 0;
	list = NULL;
	if (g_data.recieved)
		list = ft_lstnew_mini(g_data.recieved[i]);
	i++;
	while (g_data.recieved && g_data.recieved[i])
	{
		ft_lstadd_back_mini(&list, ft_lstnew_mini(g_data.recieved[i]));
		i++;
	}
	return (list);
}

static t_token	*ft_lstnew_mini(char *argv)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (node == NULL)
		return (NULL);
	node->str = ft_strdup(argv);
	node->type = VOID;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

static t_token	*ft_lstlast_mini(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (lst);
}

static void	ft_lstadd_back_mini(t_token **lst, t_token *new)
{
	if (*lst)
	{
		new->prev = ft_lstlast_mini(*lst);
		ft_lstlast_mini(*lst)->next = new;
	}
}
