/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:44 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/15 21:40:53 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_sort_matrix(char **env)
{
	int		cnt;
	int		cnt2;
	int		size;
	char	*tmp;

	cnt = 0;
	while (env[cnt])
		cnt++;
	size = cnt;
	cnt = 0;
	while (cnt < size)
	{
		cnt2 = 0;
		while (cnt2 < size - cnt - 1)
		{
			if (ft_strcmpup(env[cnt2], env[cnt2 + 1]) > 0)
			{
				tmp = env[cnt2];
				env[cnt2] = env[cnt2 + 1];
				env[cnt2 + 1] = tmp;
			}
			cnt2++;
		}
		cnt++;
	}
}

void	ft_reasign(char *name, char *value)
{
	int		cnt;
	char	**tmp;
	char	*tmp2;

	cnt = 0;
	while (g_data.env[cnt])
	{
		tmp = ft_split(g_data.env[cnt], '=');
		if (ft_strncmp(tmp[0], name, ft_strlen(name)) == 0)
		{
			free(g_data.env[cnt]);
			tmp2 = ft_strjoin(name, "=");
			g_data.env[cnt] = ft_strjoin(tmp2, value);
			free(tmp2);
			tmp = ft_clean_matrix(tmp);
			return ;
		}
		tmp = ft_clean_matrix(tmp);
		cnt++;
	}
	g_data.vars_mod = 1;
}

int	ft_exists_var(char *var)
{
	int	cnt;
	int	eq;

	cnt = 0;
	eq = 0;
	while (var[eq] != '=' && var[eq])
		eq++;
	while (g_data.env[cnt])
	{
		if (ft_strncmp(g_data.env[cnt], var, eq) == 0)
			return (1);
		cnt++;
	}
	return (0);
}

void	ft_new_env(char *name, char *value)
{
	int		cnt;
	int		cnt2;
	char	*tmp;
	char	**env;

	cnt = 0;
	cnt2 = 0;
	while (g_data.env[cnt])
		cnt++;
	env = malloc(sizeof(char *) * (cnt + 2));
	while (g_data.env[cnt2])
	{
		env[cnt2] = ft_strdup(g_data.env[cnt2]);
		cnt2++;
	}
	tmp = ft_strjoin(name, "=");
	if (!value)
		env[cnt2] = ft_empty_var(tmp);
	else
		env[cnt2] = ft_strjoin(tmp, value);
	env[cnt2 + 1] = NULL;
	g_data.env = ft_clean_matrix(g_data.env);
	g_data.env = ft_dup_envs(env);
	env = ft_clean_matrix(env);
	free(tmp);
}

void	ft_export(char **argv)
{
	int	cnt;

	if (!argv[1])
	{
		ft_sort_matrix(g_data.env);
		ft_print_matrix(g_data.env);
	}
	else
	{
		cnt = 1;
		while (argv[cnt])
		{
			ft_export_vars(argv[cnt]);
			cnt++;
		}
	}
}
