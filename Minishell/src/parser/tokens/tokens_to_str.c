/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:12:04 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/16 10:02:49 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_strlen_tokens(void);
static void	ft_tokens_to_recivied(void);

void	ft_tokens_to_str(void)
{
	int		i;
	int		n;
	char	*str;
	t_token	*aux;

	n = 0;
	aux = g_data.tokens;
	str = (char *)ft_calloc(ft_strlen_tokens() + 1, sizeof(char *));
	while (g_data.tokens)
	{
		i = 0;
		while (g_data.tokens->str[i])
			str[n++] = g_data.tokens->str[i++];
		g_data.tokens = g_data.tokens->next;
		if (g_data.tokens)
			str[n++] = 32;
	}
	g_data.tokens = aux;
	g_data.line = ft_strdup(str);
	free (str);
	ft_tokens_to_recivied();
}

static int	ft_strlen_tokens(void)
{
	int		len;
	t_token	*aux;

	len = 0;
	aux = g_data.tokens;
	while (g_data.tokens)
	{
		len += ft_strlen(g_data.tokens->str);
		g_data.tokens = g_data.tokens->next;
		if (g_data.tokens)
			len++;
	}
	g_data.tokens = aux;
	return (len);
}

static void	ft_tokens_to_recivied(void)
{
	int		i;
	int		len;
	t_token	*aux;

	len = 0;
	aux = g_data.tokens;
	while (g_data.tokens)
	{
		len++;
		g_data.tokens = g_data.tokens->next;
	}
	g_data.tokens = aux;
	if (g_data.recieved)
		g_data.recieved = ft_clean_matrix(g_data.recieved);
	g_data.recieved = (char **)ft_calloc((len + 1), sizeof(char *));
	i = 0;
	while (g_data.tokens)
	{
		g_data.recieved[i] = ft_strdup(g_data.tokens->str);
		i++;
		g_data.tokens = g_data.tokens->next;
	}
	g_data.tokens = aux;
}
