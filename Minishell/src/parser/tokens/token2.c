/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:27:39 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/23 17:57:31 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_is_command(t_token *token)
{
	if (!token->prev || token->prev->type == PIPE)
		return (1);
	return (0);
}

int	ft_is_env(t_token *token)
{
	int	i;

	i = 0;
	while (token->str[i])
	{
		if (token->str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_double_quote(t_token *token)
{
	int	i;

	i = 0;
	while (token->str[i])
	{
		if (token->str[i] == '\'')
		{
		}
		if (token->str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}
