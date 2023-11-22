/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:40:43 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/15 21:16:06 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_check_red_2(t_token *tokens);
static int	ft_check_red_3(t_token *tokens);

int	ft_check_redirections(void)
{
	t_token	*aux;

	aux = g_data.tokens;
	while (g_data.tokens)
	{
		if (ft_check_red_2(g_data.tokens) == 0)
		{
			g_data.tokens = aux;
			return (0);
		}
		if (ft_check_red_3(g_data.tokens) == 0)
		{
			g_data.tokens = aux;
			return (0);
		}
		g_data.tokens = g_data.tokens->next;
	}
	g_data.tokens = aux;
	return (1);
}

static int	ft_check_red_2(t_token *tokens)
{
	if ((tokens->type == IN_RED || tokens->type == OUT_RED || \
		tokens->type == HERE_DOC_RED || \
		tokens->type == APPEND_RED || tokens->type == PIPE) && \
		(!tokens->prev || (!tokens->next || tokens->next == NULL)))
		return (0);
	return (1);
}

static int	ft_check_red_3(t_token *tokens)
{
	if ((tokens->type == IN_RED || tokens->type == OUT_RED || \
		tokens->type == HERE_DOC_RED || \
		tokens->type == APPEND_RED || tokens->type == PIPE) && \
		(tokens->next->type == IN_RED || tokens->next->type == OUT_RED || \
		tokens->next->type == HERE_DOC_RED || \
		tokens->next->type == APPEND_RED || tokens->next->type == PIPE))
		return (0);
	return (1);
}
