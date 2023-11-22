/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:53:54 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/16 19:53:55 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_child(char *cmd, int flag)
{
	char	**args;
	char	*path;

	close(g_data.spipe.fds[0]);
	if (g_data.spipe.fd_in != 0)
		dup2(g_data.spipe.fd_in, 0);
	else
		dup2(g_data.spipe.prev_pipe, g_data.spipe.fd_in);
	if (flag)
		dup2(g_data.spipe.fds[1], g_data.spipe.fd_out);
	if (g_data.spipe.fd_out != 1)
	{
		dup2(g_data.spipe.fd_out, 1);
		g_data.spipe.fd_in = dup(g_data.spipe.fd_out);
	}
	else
		g_data.spipe.fd_in = 0;
	close(g_data.spipe.fds[1]);
	args = ft_split(cmd, ' ');
	path = ft_get_cmdpath(args[0]);
	if (execve(path, args, g_data.env) < 0)
		exit(1);
}

static void	ft_parent(void)
{
	close(g_data.spipe.fds[1]);
	waitpid(g_data.r_pid, &g_data.exit_status, 0);
	g_data.spipe.prev_pipe = g_data.spipe.fds[0];
}

void	ft_check_pipe(char *command)
{
	int		saved_stdout;
	int		saved_stdin;
	char	*tmp;

	saved_stdout = dup(1);
	saved_stdin = dup(0);
	if (ft_strchr(command, '|') && !ft_is_comma(g_data.tokens))
		ft_pipe(command);
	else
	{
		tmp = ft_check_redir_single(command);
		if (g_data.spipe.fd_in != 0)
		{
			dup2(g_data.spipe.fd_in, 0);
			close(g_data.spipe.fd_in);
		}
		if (g_data.spipe.fd_out != 1)
		{
			dup2(g_data.spipe.fd_out, 1);
			close(g_data.spipe.fd_out);
		}
		ft_cmds();
		ft_restore_fds(saved_stdout, saved_stdin);
	}
}

int	ft_exists(char *cmd)
{
	if (cmd)
		return (1);
	return (0);
}

void	ft_pipe(char *line)
{
	int		cnt;
	char	**cmdp;

	cnt = -1;
	cmdp = ft_split(line, '|');
	g_data.spipe.prev_pipe = 0;
	while (cmdp[++cnt])
	{
		pipe(g_data.spipe.fds);
		cmdp[cnt] = ft_check_redir_pipe(cmdp[cnt]);
		g_data.r_pid = fork();
		if (!cmdp[cnt])
			break ;
		if (g_data.r_pid == -1)
			exit(1);
		if (g_data.r_pid == 0)
			ft_child(cmdp[cnt], ft_exists(cmdp[cnt + 1]));
		else
			ft_parent();
	}
	close(g_data.spipe.prev_pipe);
	cmdp = ft_clean_matrix(cmdp);
}
