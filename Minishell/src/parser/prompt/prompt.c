/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:36 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/15 22:20:16 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_all_spaces(char *str);
static int	ft_c_quotes(char *str);

int	ft_check_prompt(void)
{
	if (!g_data.prompt || g_data.prompt[0] == '\0')
		return (0);
	if (ft_all_spaces(g_data.prompt))
		return (0);
	if (ft_c_quotes(g_data.prompt) == 0)
		return (add_history(g_data.prompt), \
		ft_print_errors(QUOTES), g_data.exit_status = 1, 0);
	return (1);
}

static int	ft_all_spaces(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] == ' ' && str[i])
		i++;
	if (str && !str[i])
		return (1);
	return (0);
}

static int	ft_c_quotes(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (!str[i] || str[i] != '\'')
				return (0);
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\"')
				i++;
			if (!str[i] || str[i] != '\"')
				return (0);
		}
		i++;
	}
	return (1);
}
