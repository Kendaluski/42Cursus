/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:06:03 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/16 16:59:55 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	ft_one_simple_quotes(int *n, int *i, t_token *tokens);
static void	ft_norma(t_token *tokens, int *i, int *aux);
static char	*ft_obtain_env(t_token *tokens, int i);
static char	*ft_change_env_str(t_token *tokens, char *content, char *env);

void	ft_expand_env(t_token *tokens)
{
	t_env	d;

	d.env = NULL;
	d.i = -1;
	d.aux = 0;
	while (tokens->str && tokens->str[++d.i])
	{
		ft_norma(tokens, &d.i, &d.aux);
		if (tokens->str[d.i] == '\'' && d.aux == 0)
			ft_one_simple_quotes(&d.n, &d.i, tokens);
		else if (tokens->str[d.i] == '$')
		{
			d.env = ft_obtain_env(tokens, ++d.i);
			break ;
		}
	}
	if (!d.env)
		return ;
	d.content = ft_get_env(d.env);
	if (d.content == NULL)
		d.content = ft_calloc(1, 1);
	tokens->str = ft_change_env_str(tokens, d.content, d.env);
	free(d.env);
	free(d.content);
}

static void	ft_norma(t_token *tokens, int *i, int *aux)
{
	if (tokens->str[*i] == '\"' && *aux == 0)
		*aux = 1;
	else if (tokens->str[*i] == '\"' && *aux == 1)
		*aux = 0;
}

static void	ft_one_simple_quotes(int *n, int *i, t_token *tokens)
{
	*n = *i;
	while (tokens->str && tokens->str[++(*i)] && tokens->str[*i] != '\'')
		;
	if (!tokens->str[*i])
		*i = *n;
}

static char	*ft_obtain_env(t_token *tokens, int i)
{
	int		n;
	int		len;
	char	*env;

	if (tokens->str[i] == '?')
		return (env = (char *)ft_calloc(2, sizeof(char)), env[0] = '?', env);
	n = i;
	len = 0;
	while (tokens->str[n] && (tokens->str[n] == '_' || \
	ft_isalnum(tokens->str[n]) == 1))
	{
		len++;
		n++;
	}
	env = (char *)ft_calloc((len + 1), sizeof(char));
	if (!env)
		return (NULL);
	n = 0;
	while (tokens->str[i] && (tokens->str[i] == '_' || \
	ft_isalnum(tokens->str[i]) == 1))
		env[n++] = tokens->str[i++];
	return (env);
}

static char	*ft_change_env_str(t_token *tokens, char *content, char *env)
{
	char	*str;
	int		i;
	int		len;
	int		len_env;

	len = ft_strlen(tokens->str);
	len_env = ft_strlen(env);
	if (!ft_strcmp(env, "?"))
		ft_len_change_env(&len_env);
	str = (char *)ft_calloc((len - len_env + ft_strlen(content)), sizeof(char));
	i = -1;
	len = -1;
	while (tokens->str[++i] != '$')
		str[++len] = tokens->str[i];
	while (tokens->str[++i] && (tokens->str[i] != '$' && \
	(tokens->str[i] == '_' || ft_isalnum(tokens->str[i]))))
		;
	if (tokens->str[i - 1] == '$' && tokens->str[i] == '?')
		i++;
	len_env = -1;
	while (content[++len_env])
		str[++len] = content[len_env];
	while (tokens->str[i])
		str[++len] = tokens->str[i++];
	return (free(tokens->str), str);
}
