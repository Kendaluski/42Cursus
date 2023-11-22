/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:03:57 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/15 15:48:07 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	ft_take_word(char *str, int *i, int *aux, size_t *len);
static void	ft_close_quotes(char *str, int *i, size_t *len);
static char	*ft_complete_word(char *s, int *i, int *aux, size_t len);

char	**ft_mini_split(char *s)
{
	char	**str;
	int		i;
	int		j;
	int		aux;
	size_t	len;

	str = (char **)ft_calloc((ft_words(s) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s && s[i] == ' ')
		i++;
	while (s && s[i])
	{
		aux = 0;
		len = 0;
		ft_take_word(s, &i, &aux, &len);
		str[j] = ft_complete_word(s, &i, &aux, len);
		while (s[i] == ' ')
			i++;
		j++;
	}
	return (str);
}

static void	ft_take_word(char *str, int *i, int *aux, size_t *len)
{
	int	point;

	point = 0;
	*aux = *i;
	while (str && str[*i] && !ft_strchr(" |<>", str[*i]))
	{
		point = 1;
		if (str[*i] == '\'' || str[*i] == '\"')
			ft_close_quotes(str, i, len);
		(*i)++;
		(*len)++;
	}
	if (!point && str && (str[*i] == '<' || \
		str[*i] == '>') && str[*i + 1] == str[*i])
	{
		(*i) += 2;
		(*len) += 2;
	}
	else if (!point && str && (str[*i] == '<' || \
			str[*i] == '>' || str[*i] == '|'))
	{
		(*i)++;
		(*len)++;
	}
}

static void	ft_close_quotes(char *str, int *i, size_t *len)
{
	char	quote;

	quote = str[*i];
	(*i)++;
	(*len)++;
	while (str && str[*i] && str[*i] != quote)
	{
		(*i)++;
		(*len)++;
	}
}

static char	*ft_complete_word(char *s, int *i, int *aux, size_t len)
{
	char	*str;
	int		n;

	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	n = 0;
	while (s && s[*aux] && *aux != *i)
	{
		str[n] = s[*aux];
		n++;
		(*aux)++;
	}
	return (str);
}
