/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:50:22 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/01/31 17:28:18 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_philo	*ft_join_threads(t_philo *list)
{
	t_philo	*tmp;

	tmp = list;
	while (tmp)
	{
		pthread_join(tmp->thread_id, NULL);
		tmp = tmp->next;
	}
	return (list);
}

void	ft_change_status(t_fork *fork1, t_fork *fork2, t_philo *philo,
		int action)
{
	if (action == 0 && fork1->status == 1 && fork2->status == 1)
	{
		pthread_mutex_unlock(&fork1->mutex);
		pthread_mutex_unlock(&fork2->mutex);
		fork1->status = 0;
		fork2->status = 0;
		fork1->philo_id = -1;
		fork2->philo_id = -1;
	}
	else if (action == 1 && fork1->status == 0 && fork2->status == 0)
	{
		if (!pthread_mutex_lock(&fork1->mutex))
			printf("[%ld] Philosopher %i has taken a fork\n",
				ft_current_time(philo->program_start),
				philo->id);
		if (!pthread_mutex_lock(&fork2->mutex))
			printf("[%ld] Philosopher %i has taken a fork\n",
				ft_current_time(philo->program_start),
				philo->id);
		fork1->status = 1;
		fork2->status = 1;
		fork1->philo_id = philo->id;
		fork2->philo_id = philo->id;
	}
}

void	ft_first_fork(t_fork *first, t_fork *second, t_philo *philo, int action)
{
	ft_change_status(first, second, philo, action);
}

void	ft_pick_forks(t_fork *forks, t_philo *philo, int action)
{
	t_fork	*tmp;
	t_fork	*tmp2;

	tmp = forks;
	tmp2 = NULL;
	if (philo->id == 1)
		ft_first_fork(tmp, ft_last(forks), philo, action);
	else
	{
		tmp = forks->next;
		while (tmp->next && tmp->id != philo->id)
		{
			if (tmp->id == philo->id)
			{
				tmp2 = tmp->next;
				ft_change_status(tmp, tmp2, philo, action);
			}
			tmp = tmp->next;
		}
		if (tmp->id == philo->id)
		{
			tmp2 = forks;
			ft_change_status(tmp, tmp2, philo, action);
		}
	}
}
