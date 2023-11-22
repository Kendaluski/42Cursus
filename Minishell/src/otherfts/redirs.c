/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:45:26 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/16 19:36:57 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_heredoc(char *limiter)
{
	char	*line;
	char	*test;
	int		fd;

	fd = open("tmp", O_CREAT | O_RDWR, 0644);
	test = ft_eof(limiter);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		line = ft_nl(line);
		if (ft_strcmp(line, test) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
	g_data.vars_mod = 10;
	g_data.spipe.fd_in = open("tmp", O_RDONLY);
}

int	ft_double_redir_ck(char *line, char red)
{
	int	cnt;
	int	flag;

	flag = 0;
	cnt = 0;
	while (line[cnt])
	{
		if (line[cnt] == red && line[cnt + 1] == red)
			flag = 1;
		cnt++;
	}
	return (flag);
}

char	*ft_in_redir(char *line)
{
	char	**cmd;
	char	*tmp;

	cmd = ft_split(line, '<');
	if (ft_exists(cmd[2]))
	{
		printf("[ERROR] Infile redirection error\n");
		g_data.exit_status = 1;
		cmd = ft_clean_matrix(cmd);
		return (NULL);
	}
	tmp = ft_strtrim(cmd[0], " ");
	free(cmd[0]);
	cmd[0] = tmp;
	tmp = ft_strtrim(cmd[1], " ");
	free(cmd[1]);
	cmd[1] = tmp;
	if (ft_double_redir_ck(line, '<'))
		ft_heredoc(cmd[1]);
	else
		g_data.spipe.fd_in = open(cmd[1], O_RDONLY);
	g_data.recieved = ft_realloc_recieved();
	tmp = ft_strdup(cmd[0]);
	cmd = ft_clean_matrix(cmd);
	return (tmp);
}

char	*ft_out_redir(char *line)
{
	char	**cmd;
	char	*tmp;

	cmd = ft_split(line, '>');
	if (ft_exists(cmd[2]))
	{
		printf("[ERROR] Outfile redirection error\n");
		g_data.exit_status = 1;
		cmd = ft_clean_matrix(cmd);
		return (NULL);
	}
	else
	{
		tmp = ft_strtrim(cmd[1], " ");
		if (ft_double_redir_ck(line, '>'))
			g_data.spipe.fd_out = open(tmp, O_CREAT | O_WRONLY | O_APPEND,
					0644);
		else
			g_data.spipe.fd_out = open(tmp, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		free(tmp);
	}
	tmp = ft_strtrim(cmd[0], " ");
	cmd = ft_clean_matrix(cmd);
	g_data.recieved = ft_realloc_recieved();
	return (tmp);
}

char	*ft_check_redir_pipe(char *line)
{
	char	*tmp;

	g_data.spipe.fd_in = 0;
	g_data.spipe.fd_out = 1;
	if (!line)
		return (NULL);
	if (ft_strchr(line, '>') && !ft_is_comma(g_data.tokens))
	{
		tmp = ft_out_redir(line);
		free(line);
		line = ft_strdup(tmp);
		free(tmp);
	}
	if (ft_strchr(line, '<') && !ft_is_comma(g_data.tokens))
	{
		tmp = ft_in_redir(line);
		free(line);
		line = ft_strdup(tmp);
		free(tmp);
	}
	if (!line)
		return (NULL);
	return (line);
}
