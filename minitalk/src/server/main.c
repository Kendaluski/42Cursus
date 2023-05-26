/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:09:57 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/26 19:26:15 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_bin_to_char(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	cnt = 0;

	(void)context;
	if (!info)
		return ;
	if (signal == SIGUSR1)
		c = c << 1 | 1;
	else if (signal == SIGUSR2)
		c = c << 1;
	cnt++;
	if (cnt == 8)
	{
		write(1, &c, 1);
		if (c == 0)
			write(1, "\n", 1);
		cnt = 0;
		c = 0;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	aux;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 2147483647)
		write(fd, "2147483647", 10);
	else
	{
		if (n < 0)
		{
			n = n * -1;
			write(fd, "-", 1);
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			aux = n + 48;
			write(fd, &aux, 1);
		}
	}
}

int	main(void)
{
	struct sigaction	signal;

	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = ft_bin_to_char;
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &signal, NULL);
		sigaction(SIGUSR2, &signal, NULL);
		pause();
	}
	return (0);
}
