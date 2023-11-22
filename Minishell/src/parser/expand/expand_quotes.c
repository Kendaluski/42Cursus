/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:18:10 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/15 21:22:36 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_expand_quotes(char *quote)
{
	char	*str;
	int		i;
	int		n;

	i = -1;
	n = 0;
	str = ft_strdup(quote);
	if (!quote)
		return ;
	while (str && str[++i])
	{
		if (str[i] == '\'')
			while (str[++i] != '\'')
				quote[n++] = str[i];
		else if (str[i] == '\"')
			while (str[++i] != '\"')
				quote[n++] = str[i];
		else if (str[i])
			quote[n++] = str[i];
	}
	while (quote && quote[n] != '\0')
		quote[n++] = '\0';
	free (str);
}
