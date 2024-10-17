/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:50:22 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/02/08 23:57:20 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_philo	*ft_join_threads(t_philo *list)
{
	t_philo	*tmp;

	tmp = list;
	while (tmp->next)
	{
		pthread_join(tmp->thread_id, NULL);
		tmp = tmp->next;
	}
	return (list);
}

int	ft_get_forks(t_fork *fork1, t_fork *fork2, t_philo *philo)
{
	pthread_mutex_lock(&fork1->mutex);
	if (ft_check_exit(philo))
	{
		pthread_mutex_unlock(&fork1->mutex);
		return (0);
	}
	printf("[%ld] Philosopher %i has taken the first fork\n",
		ft_current_time(philo->program_start),
		philo->id);
	pthread_mutex_lock(&fork2->mutex);
	if (ft_check_exit(philo))
	{
		pthread_mutex_unlock(&fork2->mutex);
		return (0);
	}
	printf("[%ld] Philosopher %i has taken the second fork\n",
		ft_current_time(philo->program_start),
		philo->id);
	fork1->status = 1;
	fork2->status = 1;
	return (1);
}

int	ft_change_status(t_fork *fork1, t_fork *fork2, t_philo *philo, int action)
{
	if (action == 0)
	{
		pthread_mutex_unlock(&fork1->mutex);
		pthread_mutex_unlock(&fork2->mutex);
		fork1->status = 0;
		fork2->status = 0;
		return (1);
	}
	else if (action == 1)
		return (ft_get_forks(fork1, fork2, philo));
	return (0);
}

int	ft_first_fork(t_fork *first, t_fork *second, t_philo *philo, int action)
{
	return (ft_change_status(first, second, philo, action));
}

int	ft_pick_forks(t_fork *forks, t_philo *philo, int action)
{
	t_fork	*tmp;
	t_fork	*tmp2;

	tmp = forks;
	while (tmp->next->next)
	{
		if (tmp->id == philo->id)
		{
			tmp2 = tmp->next;
			return (ft_change_status(tmp, tmp2, philo, action));
		}
		tmp = tmp->next;
	}
	if (tmp->id == philo->id)
	{
		tmp2 = forks;
		return (ft_change_status(tmp, tmp2, philo, action));
	}
	return (0);
}
