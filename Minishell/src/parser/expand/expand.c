/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:54:16 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/15 20:58:48 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	ft_one_simple_quo_data(int *n, int *i, t_token *tokens);

void	ft_expand_data(void)
{
	t_token	*aux;
	int		i;
	int		n;

	aux = g_data.tokens;
	while (g_data.tokens)
	{
		i = -1;
		while (g_data.tokens && g_data.tokens->str && g_data.tokens->str[++i])
		{
			if (g_data.tokens->str[i] == '\'')
				ft_one_simple_quo_data(&n, &i, g_data.tokens);
			else if (g_data.tokens->str && g_data.tokens->str[i] == '$')
			{
				ft_expand_env(g_data.tokens);
				i = -1;
			}
		}
		ft_expand_quotes(g_data.tokens->str);
		g_data.tokens = g_data.tokens->next;
	}
	g_data.tokens = aux;
}

static void	ft_one_simple_quo_data(int *n, int *i, t_token *tokens)
{
	*n = *i;
	while (tokens->str && tokens->str[++(*i)] && tokens->str[*i] != '\'')
		;
	if (!tokens->str[*i])
		*i = *n;
}
