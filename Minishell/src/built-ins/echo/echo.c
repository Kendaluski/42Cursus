/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:13:05 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/16 19:43:52 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	ft_status(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$')
	{
		i++;
		if (str[i] == '?')
			return (1);
	}
	return (0);
}

static int	ft_is_full_n(char *str)
{
	int	cnt;

	cnt = 0;
	if (str[0] == '-' && str[1] == 'n')
	{
		cnt++;
		while (str[cnt])
		{
			if (str[cnt] != 'n')
				return (0);
			cnt++;
		}
		if (str[cnt] == '\0')
			return (1);
	}
	return (0);
}

static int	ft_is_flag(char **argv, int cnt)
{
	int	cnt2;

	cnt2 = 1;
	if (!ft_is_full_n(argv[cnt]))
		return (0);
	while (argv[cnt2] && cnt2 != cnt)
	{
		if (!ft_is_full_n(argv[cnt2]))
			return (0);
		cnt2++;
	}
	return (1);
}

void	ft_print(char **argv, int cnt)
{
	if (ft_status(argv[cnt]) == 1)
		ft_printf("%i", g_data.exit_status);
	else
		ft_putstr(argv[cnt]);
	if (argv[cnt + 1])
		write(1, " ", 1);
}

void	ft_echo(char **argv)
{
	int	cnt;
	int	flag;

	cnt = 1;
	flag = 0;
	if (!argv[1])
	{
		write(1, "\n", 1);
		return ;
	}
	while (argv[cnt])
	{
		if (ft_is_flag(argv, cnt))
		{
			flag = 1;
			cnt++;
			continue ;
		}
		ft_print(argv, cnt);
		cnt++;
	}
	if (!flag)
		printf("\n");
	g_data.exit_status = 0;
}
