/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:50:22 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/01/30 20:55:01 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void ft_exit(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp)
	{
		printf("Detach %i\n", tmp->id);
		//pthread_detach(tmp->thread_id);
		tmp = tmp->next;
	}
	exit(0);
}

t_philo	*ft_join_threads(t_philo *list)
{
	t_philo	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("Join %i\n", tmp->id);
		pthread_join(tmp->thread_id, NULL);
		tmp = tmp->next;
	}
	return (list);
}

void ft_change_status(t_fork *fork1, t_fork *fork2, int philoid, int action)
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
		pthread_mutex_lock(&fork1->mutex);
		pthread_mutex_lock(&fork2->mutex);
		fork1->status = 1;
		fork2->status = 1;
		fork1->philo_id = philoid;
		fork2->philo_id = philoid;
	}
}

void	ft_pick_forks(t_fork *forks, int philoid, int action)
{
	t_fork	*tmp;
	t_fork	*tmp2;

	tmp = forks;
	tmp2 = NULL;
	if (philoid == 1)
	{
		tmp2 = ft_last(forks);
		ft_change_status(tmp, tmp2, philoid, action);
	}
	else
	{
		tmp = forks->next;
		while (tmp->next && tmp->id != philoid)
		{
			if (tmp->id == philoid)
			{
				tmp2 = tmp->next;
				ft_change_status(tmp, tmp2, philoid, action);
			}
			tmp = tmp->next;
		}
		if(tmp->id == philoid)
		{
			tmp2 = forks;
			ft_change_status(tmp, tmp2, philoid, action);
		}
	}
}
