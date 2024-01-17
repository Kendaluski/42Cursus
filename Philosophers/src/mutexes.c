/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:50:22 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/01/17 20:40:44 by jjaen-mo         ###   ########.fr       */
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
