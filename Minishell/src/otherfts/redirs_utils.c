/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:57:45 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/16 19:32:29 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_check_redir_single(char *line)
{
	char	*tmp;

	g_data.spipe.fd_in = 0;
	g_data.spipe.fd_out = 1;
	if (!line)
		return (NULL);
	if (ft_strchr(line, '>') && !ft_is_comma(g_data.tokens))
	{
		tmp = ft_out_redir(line);
		free(g_data.line);
		g_data.line = NULL;
		g_data.line = ft_strdup(tmp);
		free(tmp);
	}
	if (ft_strchr(g_data.line, '<') && !ft_is_comma(g_data.tokens))
	{
		tmp = ft_in_redir(line);
		free(g_data.line);
		g_data.line = NULL;
		g_data.line = ft_strdup(tmp);
		free(tmp);
	}
	if (!line)
		return (NULL);
	return (line);
}
