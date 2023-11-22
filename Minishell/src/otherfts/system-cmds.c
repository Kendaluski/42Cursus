/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system-cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:41:41 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/16 17:42:15 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_clean_matrix(char **matrix)
{
	int	cnt;

	cnt = 0;
	while (matrix[cnt])
	{
		if (matrix[cnt])
			free(matrix[cnt]);
		cnt++;
	}
	if (matrix)
		free(matrix);
	return (NULL);
}

char	*ft_get_env(char *str)
{
	int		cnt;
	char	*env;

	if (str[0] == '?')
		return (ft_itoa(g_data.exit_status));
	cnt = 0;
	while (g_data.env[cnt])
	{
		if (ft_strncmp(g_data.env[cnt], str, ft_strlen(str)) == 0
			&& g_data.env[cnt][ft_strlen(str)] == '=')
		{
			env = ft_strdup(g_data.env[cnt] + (ft_strlen(str) + 1));
			return (env);
		}
		cnt++;
	}
	return (NULL);
}

static int	ft_check_file(char *cmd)
{
	int	cnt;

	cnt = 0;
	while (cmd[cnt])
	{
		if (cmd[cnt] == '/')
		{
			if (access(cmd, F_OK) < 0)
			{
				printf("[ERROR] Not such file or directory \n");
				g_data.exit_status = 127;
				return (1);
			}
		}
		cnt++;
	}
	return (0);
}

char	*ft_get_cmdpath(char *cmd)
{
	int		cnt;
	int		exists;
	char	*cmdpath;
	char	**path;
	char	*tmp;

	cnt = -1;
	exists = 1;
	while (cmd[++cnt])
	{
		if (cmd[cnt] == '/')
			exists = access(cmd, F_OK);
	}
	if (!exists)
		return (ft_strdup(cmd));
	tmp = ft_get_env("PATH");
	if (!tmp)
		return (NULL);
	path = ft_split(tmp, ':');
	free(tmp);
	cmdpath = ft_path(path, cmd);
	if (cmdpath)
		return (cmdpath);
	ft_clean_matrix(path);
	return (NULL);
}

void	ft_system_cmds(char **command)
{
	char	*cmdpath;

	if (ft_check_file(command[0]) == 1)
		return ;
	cmdpath = NULL;
	cmdpath = ft_get_cmdpath(command[0]);
	if (!cmdpath)
	{
		printf("[ERROR] Command not found: %s\n", command[0]);
		g_data.exit_status = 127;
	}
	else
	{
		ft_exec(cmdpath, command);
		if (cmdpath)
		{
			free(cmdpath);
			cmdpath = NULL;
		}
	}
}
