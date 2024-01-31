/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:28:00 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/01/31 14:58:00 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_philo_eat(t_philo *philo)
{
	long	time;

	ft_pick_forks(philo->first_fork, philo, 1);
	philo->status = EATING;
	printf("[%ld] Philosopher %i is eating\n",
		ft_current_time(philo->program_start),
		philo->id);
	philo->last_eaten = ft_current_time(philo->program_start);
	time = ft_current_time(philo->program_start) + philo->eat_time;
	while (ft_current_time(philo->program_start) <= time)
	{
		if (philo->status == FINISHED)
			break ;
		usleep(1);
	}
	philo->eat_count++;
	ft_pick_forks(philo->first_fork, philo, 0);
}

void	ft_philo_sleep(t_philo *philo)
{
	long	time;

	philo->status = SLEEPING;
	printf("[%ld] Philosopher %i is sleeping\n",
		ft_current_time(philo->program_start),
		philo->id);
	time = ft_current_time(philo->program_start) + philo->sleep_time;
	while (ft_current_time(philo->program_start) <= time)
	{
		if (philo->status == FINISHED)
			break ;
		usleep(1);
	}
}

void	ft_philo_think(t_philo *philo)
{
	long	time;

	philo->status = THINKING;
	printf("[%ld] Philosopher %i is thinking\n",
		ft_current_time(philo->program_start),
		philo->id);
	time = philo->die_time - ft_current_time(philo->program_start)
		- philo->last_eaten - philo->eat_time;
	while (ft_current_time(philo->program_start) <= time)
	{
		if (philo->status == FINISHED)
			break ;
		usleep(1);
	}
}

int	ft_check_finish(t_philo *philo)
{
	if (ft_current_time(philo->program_start)
		- philo->last_eaten > philo->die_time)
	{
		philo->status = DEAD;
		printf("[%ld] Philosopher %i died\n",
			ft_current_time(philo->program_start),
			philo->id);
		return (1);
	}
	return (0);
}
