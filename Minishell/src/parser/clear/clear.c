/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:52:42 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/16 14:15:12 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_clear(void)
{
	if (g_data.recieved)
		g_data.recieved = ft_clean_matrix(g_data.recieved);
	if (g_data.vars_mod == 10)
		unlink("tmp");
	if (g_data.line || g_data.line[0] != '\0')
		free(g_data.line);
	ft_clear_tokens();
	g_data.line = NULL;
}

void	ft_clear_parser(int i)
{
	if (i == 0)
	{
		if (g_data.recieved)
			g_data.recieved = ft_clean_matrix(g_data.recieved);
	}
	else if (i == 1)
	{
		if (g_data.recieved)
			g_data.recieved = ft_clean_matrix(g_data.recieved);
		if (g_data.tokens)
			ft_clear_tokens();
	}
}

void	ft_clean_double_pointer(char **matrix)
{
	int		cnt;

	cnt = 0;
	while (matrix[cnt + 1])
	{
		free(matrix[cnt]);
		cnt++;
	}
	free(matrix);
	matrix = NULL;
}

void	ft_clear_tokens(void)
{
	t_token	*next;

	next = NULL;
	while (g_data.tokens)
	{
		next = g_data.tokens->next;
		if (g_data.tokens->str)
			free (g_data.tokens->str);
		if (g_data.tokens)
			free (g_data.tokens);
		g_data.tokens = next;
	}
}
