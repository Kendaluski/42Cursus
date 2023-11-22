/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:52:26 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/16 14:09:23 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	**ft_split_var(char *argv)
{
	char	**vars;

	vars = malloc(sizeof(char *) * 3);
	vars[0] = ft_substr(argv, 0, ft_strchr(argv, '=') - argv);
	vars[1] = ft_substr(argv, ft_strchr(argv, '=') - argv + 1, ft_strlen(argv));
	vars[2] = NULL;
	return (vars);
}

char	*ft_empty_var(char *name)
{
	char	*tmp;

	tmp = ft_strjoin(name, "");
	return (tmp);
}

int	ft_is_valid_name(char *name)
{
	int	cnt;

	cnt = 0;
	while (name[cnt])
	{
		if (ft_isdigit(name[cnt]) && cnt == 0)
			return (0);
		if (!ft_isalnum(name[cnt]) && name[cnt] != '_')
			return (0);
		cnt++;
	}
	return (1);
}

void	ft_export_vars(char *argv)
{
	char	**vars;

	vars = ft_split_var(argv);
	if (!vars[0])
		return ;
	if (ft_exists_var(argv) && ft_strncmp(vars[0], "$", 1))
		ft_reasign(vars[0], vars[1]);
	else if (ft_is_valid_name(vars[0]))
		ft_new_env(vars[0], vars[1]);
	else
		ft_printf("MiniSheh: export: '%s': not a valid identifier\n",
			argv);
	vars = ft_clean_matrix(vars);
}
