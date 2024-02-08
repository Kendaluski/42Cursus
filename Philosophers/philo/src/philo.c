/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:28:00 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/02/08 23:37:38 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int ft_print_status(t_philo *philo)
{
	if(ft_check_exit(philo))
		return (1);
	if (philo->status == EATING)
		printf("[%ld] Philosopher %i is eating\n",
			ft_current_time(philo->program_start),
			philo->id);
	else if (philo->status == SLEEPING)
		printf("[%ld] Philosopher %i is sleeping\n",
			ft_current_time(philo->program_start),
			philo->id);
	else if (philo->status == THINKING)
		printf("[%ld] Philosopher %i is thinking\n",
			ft_current_time(philo->program_start),
			philo->id);
	return (0);
}

void	ft_philo_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->checker_mutex);
	philo->status = EATING;
	if (ft_print_status(philo))
	{
		pthread_mutex_unlock(philo->checker_mutex);
		return ;
	}
	philo->last_eaten = ft_current_time(philo->program_start);
	pthread_mutex_unlock(philo->checker_mutex);
}

void	ft_philo_eat(t_philo *philo)
{
	long	time;

	if (ft_check_exit(philo))
		return ;
	if (!ft_pick_forks(philo->first_fork, philo, 1))
		return ;
	ft_philo_eating(philo);
	time = ft_current_time(philo->program_start) + philo->eat_time;
	while (ft_current_time(philo->program_start) <= time)
	{
		if (ft_check_exit(philo))
			break ;
		usleep(1);
	}
	pthread_mutex_lock(philo->checker_mutex);
	philo->eat_count++;
	pthread_mutex_unlock(philo->checker_mutex);
	ft_pick_forks(philo->first_fork, philo, 0);
}

void	ft_philo_sleep(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(philo->checker_mutex);
	philo->status = SLEEPING;
	if (ft_print_status(philo))
	{
		pthread_mutex_unlock(philo->checker_mutex);
		return ;
	}
	pthread_mutex_unlock(philo->checker_mutex);
	time = ft_current_time(philo->program_start) + philo->sleep_time;
	while (ft_current_time(philo->program_start) <= time)
	{
		if (ft_check_exit(philo))
			break ;
		usleep(1);
	}
}

void	ft_philo_think(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(philo->checker_mutex);
	philo->status = THINKING;
	if (ft_print_status(philo))
	{
		pthread_mutex_unlock(philo->checker_mutex);
		return ;
	}
	pthread_mutex_unlock(philo->checker_mutex);
	time = philo->die_time - ft_current_time(philo->program_start)
		- philo->last_eaten - philo->eat_time;
	while (ft_current_time(philo->program_start) <= time)
	{
		if (ft_check_exit(philo))
			break ;
		usleep(1);
	}
}
