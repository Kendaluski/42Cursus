/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:31:38 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/16 16:02:51 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	ft_pass_env(char **received, int *i, int *n);
static int	ft_mini_isalpha(int c);

int	ft_check_env_errors(char **received)
{
	int	i;
	int	n;

	i = 0;
	while (received && received[i])
	{
		n = 0;
		while (received[i][n])
		{
			if (received[i][n] == '\'')
				ft_pass_env(received, &i, &n);
			if (received[i][n] && received[i][n] == '$' && \
			ft_mini_isalpha(received[i][n + 1]))
				n += 2;
			else if (received[i][n] && received[i][n] == '$')
				return (0);
			while (received[i][n] && (received[i][n] != '$' || \
			received[i][n] != '\''))
				n++;
		}
		i++;
	}
	return (1);
}

static void	ft_pass_env(char **received, int *i, int *n)
{
	(*n)++;
	while (received[*i][*n] != '\0' && received[*i][*n] != '\'')
		(*n)++;
	if (received[*i][*n] && received[*i][*n] == '\'')
		(*n)++;
}

static int	ft_mini_isalpha(int c)
{
	return ((c == '?') || (c == '_') || \
	(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
