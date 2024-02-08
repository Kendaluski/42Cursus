/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:02:06 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/02/08 21:32:06 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_data ft_mutex_destroy(t_data data)
{
	t_fork	*tmp;
	t_philo	*philo;
	
	tmp = data.forks;
	philo = data.philos;
	while (tmp->next)
	{
		pthread_mutex_destroy(&tmp->mutex);
		tmp = tmp->next;
	}
	while (philo->next)
	{
		pthread_mutex_destroy(philo->checker_mutex);
		philo = philo->next;
	}
	pthread_mutex_destroy(&data.exit_mutex);
	return (data);
}

int	ft_check_eat(t_philo *philo, int max_eat, int philo_n)
{
	t_philo	*tmp;
	int		check;

	tmp = philo;
	check = 0;
	while (tmp->next)
	{
		pthread_mutex_lock(tmp->checker_mutex);
		if (max_eat != -1 && tmp->eat_count == max_eat)
		{
			tmp->status = FINISHED;
			check++;
		}
		pthread_mutex_unlock(tmp->checker_mutex);
		tmp = tmp->next;
	}
	if (check == philo_n)
		return (1);
	return (0);
}

int	ft_handle_death(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp->next)
	{
		pthread_mutex_lock(tmp->checker_mutex);
		if (ft_current_time(tmp->program_start)
			- tmp->last_eaten > tmp->die_time)
		{
			tmp->status = DEAD;
			printf(RED"[%ld] Philosopher %i died\n"DEFAULT,
				ft_current_time(tmp->program_start),
				tmp->id);
			pthread_mutex_unlock(tmp->checker_mutex);
			pthread_mutex_lock(&tmp->data->exit_mutex);
			tmp->data->exit = 1;
			pthread_mutex_unlock(&tmp->data->exit_mutex);
			return (1);
		}
		pthread_mutex_unlock(tmp->checker_mutex);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_exit(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->exit_mutex);
	if (philo->data->exit == 1)
	{
		pthread_mutex_unlock(&philo->data->exit_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->exit_mutex);
	return (0);
}
