/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:16:25 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/16 20:06:32 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_realloc_recieved(void)
{
	char	**tmp;
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	while (g_data.recieved[cnt])
	{
		if (ft_strchr(g_data.recieved[cnt], '>')
			|| ft_strchr(g_data.recieved[cnt], '<'))
			cnt++;
		else
			i++;
		cnt++;
	}
	tmp = malloc(sizeof(char *) * (i + 1));
	cnt = 0;
	while (cnt < i)
	{
		tmp[cnt] = ft_strdup(g_data.recieved[cnt]);
		cnt++;
	}
	tmp[cnt] = NULL;
	g_data.recieved = ft_clean_matrix(g_data.recieved);
	return (tmp);
}

void	ft_restore_fds(int stdout, int stdin)
{
	dup2(stdout, 1);
	dup2(stdin, 0);
	close(stdout);
	close(stdin);
}

int	ft_is_comma(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->type == DOUBLE_QUOTE || tokens->type == SINGLE_QUOTE)
		{
			if (ft_strchr(tokens->str, '|') || ft_strchr(tokens->str, '<')
				|| ft_strchr(tokens->str, '>'))
				return (1);
		}
		tokens = tokens->next;
	}
	return (0);
}

char	*ft_nl(char *line)
{
	char	*pos;

	pos = ft_strchr(line, '\n');
	if (pos != NULL)
		*pos = '\0';
	return (line);
}

char	*ft_eof(char *limiter)
{
	char	*test;

	if (ft_strcmp(limiter, "EOF") == 0)
		test = ft_strdup("\n");
	else
		test = limiter;
	return (test);
}
