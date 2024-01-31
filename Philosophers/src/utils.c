/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:51:42 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/01/31 14:59:58 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void ft_handle_death(t_philo *philo)
{
	philo = ft_free_philo(philo);
	philo->first_fork = ft_free_forks(philo->first_fork);
	exit(0);
}

long	ft_current_time(long start_time)
{
	struct timeval	time;
	long			timemls;

	gettimeofday(&time, NULL);
	timemls = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (timemls - start_time);
}

long	ft_start_time(void)
{
	struct timeval	time;
	long			timemls;

	gettimeofday(&time, NULL);
	timemls = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (timemls);
}

t_fork	*ft_last(t_fork *list)
{
	t_fork	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (!str || !str[i])
		return (-1);
	if (str[i] == '-')
		return (-1);
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}
