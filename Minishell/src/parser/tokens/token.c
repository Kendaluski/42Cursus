/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:39:48 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/16 17:02:57 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	ft_tokenizer_utils(void);
static int	ft_is_no_quote(char *argv);
static int	ft_is_builtin(t_token *token);
static int	ft_check_builtin(t_token *token);

void	ft_tokenizer(void)
{
	t_token	*aux;

	aux = g_data.tokens;
	while (g_data.tokens)
	{
		if (ft_is_no_quote(g_data.tokens->str))
			ft_tokenizer_utils();
		else
		{
			if (ft_is_double_quote(g_data.tokens))
				g_data.tokens->type = DOUBLE_QUOTE;
			else
				g_data.tokens->type = SINGLE_QUOTE;
		}
		g_data.tokens = g_data.tokens->next;
	}
	g_data.tokens = aux;
}

static void	ft_tokenizer_utils(void)
{
	if (ft_is_builtin(g_data.tokens))
		g_data.tokens->type = BUILTINS;
	else if (ft_is_env(g_data.tokens))
		g_data.tokens->type = ENVI_VAR;
	else if (!ft_strcmp(g_data.tokens->str, "|"))
		g_data.tokens->type = PIPE;
	else if (ft_is_command(g_data.tokens))
		g_data.tokens->type = COMMAND;
	else if (!ft_strcmp(g_data.tokens->str, "<"))
		g_data.tokens->type = IN_RED;
	else if (!ft_strcmp(g_data.tokens->str, ">"))
		g_data.tokens->type = OUT_RED;
	else if (!ft_strcmp(g_data.tokens->str, "<<"))
		g_data.tokens->type = HERE_DOC_RED;
	else if (!ft_strcmp(g_data.tokens->str, ">>"))
		g_data.tokens->type = APPEND_RED;
	else
		g_data.tokens->type = NO_QUOTE;
}

static int	ft_is_no_quote(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '\'' || argv[i] == '\"')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_builtin(t_token *token)
{
	if (!token->prev)
	{
		if (ft_check_builtin(token))
			return (1);
	}
	else if (token->prev->type == PIPE)
	{
		if (ft_check_builtin(token))
			return (1);
	}
	return (0);
}

static int	ft_check_builtin(t_token *token)
{
	if (!ft_strcmp(token->str, "echo") || !ft_strcmp(token->str, "cd") || \
	!ft_strcmp(token->str, "pwd") || !ft_strcmp(token->str, "export") || \
	!ft_strcmp(token->str, "unset") || !ft_strcmp(token->str, "env") || \
	!ft_strcmp(token->str, "exit"))
		return (1);
	return (0);
}
