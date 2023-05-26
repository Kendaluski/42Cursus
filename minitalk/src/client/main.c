/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:09:53 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/26 19:19:08 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *c)
{
	int	num;
	int	cnt;
	int	sign;

	sign = 1;
	num = 0;
	cnt = 0;
	while ((c[cnt] >= 9 && c[cnt] <= 13) || c[cnt] == 32)
		cnt++;
	if (c[cnt] == '-' || c[cnt] == '+')
	{
		if (c[cnt] == '-')
			sign = -1;
		cnt++;
	}
	while ((c[cnt] >= '0' && c[cnt] <= '9') && c[cnt] != '\0')
	{
		num = num * 10 + (c[cnt] - 48);
		cnt++;
	}
	return (num * sign);
}

void	ft_to_bin(char c, int pid)
{
	int	cnt;

	cnt = 1;
	while (cnt <= 8)
	{
		if (c >> (8 - cnt) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		cnt++;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		pid;
	int		cnt;

	if (argc == 3)
	{
		cnt = 0;
		str = argv[2];
		pid = ft_atoi(argv[1]);
		if (!pid)
			return (1);
		while (str[cnt])
		{
			ft_to_bin(str[cnt], pid);
			cnt++;
		}
		ft_to_bin(0, pid);
	}
	return (0);
}
