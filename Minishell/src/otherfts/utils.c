/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:41:56 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/16 17:40:57 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_path(char **path, char *cmd)
{
	int		cnt;
	char	*tmp;
	char	*cmdpath;

	cnt = 0;
	while (path[cnt])
	{
		tmp = ft_strjoin(path[cnt], "/");
		cmdpath = ft_strjoin(tmp, cmd);
		if (access(cmdpath, F_OK) == 0)
		{
			ft_clean_matrix(path);
			free(tmp);
			return (cmdpath);
		}
		free(cmdpath);
		free(tmp);
		cnt++;
	}
	return (NULL);
}

char	**ft_shell_lvl(char **env)
{
	char	*tmp;
	char	*tmp2;
	int		cnt;

	tmp = ft_get_env("SHLVL");
	if (!tmp)
	{
		ft_new_env("SHLVL", "1");
		return (g_data.env);
	}
	tmp2 = ft_itoa(ft_atoi(tmp) + 1);
	free(tmp);
	cnt = -1;
	while (env[++cnt])
	{
		if (ft_strncmp(env[cnt], "SHLVL", 5) == 0)
		{
			free(env[cnt]);
			env[cnt] = ft_strjoin("SHLVL=", tmp2);
			free(tmp2);
			return (env);
		}
	}
	free(tmp2);
	return (env);
}

void	ft_exec(char *cmdpath, char **command)
{
	g_data.r_pid = fork();
	if (g_data.r_pid < 0)
		printf("[ERROR] Could not create a child process \n");
	else if (g_data.r_pid == 0)
	{
		if (execve(cmdpath, command, g_data.env) < 0
			&& g_data.exit_status != 127)
			printf("[ERROR] Could not execute command %s \n", command[0]);
		exit(1);
	}
	else
		wait(&g_data.exit_status);
}

int	ft_strcmpup(char *str1, char *str2)
{
	char	*tmp1;
	char	*tmp2;
	int		ret;

	tmp1 = ft_strup(ft_strdup(str1));
	tmp2 = ft_strup(ft_strdup(str2));
	ret = ft_strcmp(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	return (ret);
}

char	*ft_strup(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		str[cnt] = ft_toupper(str[cnt]);
		cnt++;
	}
	return (str);
}
