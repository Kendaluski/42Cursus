/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:50:22 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/28 20:56:04 by jjaen-mo         ###   ########.fr       */
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

t_fork	*ft_change_status(t_fork *fork, int philoid)
{
	pthread_mutex_lock(&fork->mutex);
	fork->status = 1;
	fork->philo_id = philoid;
	return (fork);
}

void	ft_pick_forks(t_fork *forks, int philoid)
{
	t_fork	*tmp;

	tmp = forks;
	if (philoid == 1)
	{
		tmp = ft_change_status(tmp, philoid);
		tmp = ft_last(forks);
		tmp = ft_change_status(tmp, philoid);
	}
	else
	{
		while (tmp->next)
		{
			if (tmp->id == philoid)
			{
				tmp = ft_change_status(tmp, philoid);
				tmp = tmp->next;
				tmp = ft_change_status(tmp, philoid);
			}
			tmp = tmp->next;
		}
		if(tmp->id == philoid)
		{
			tmp = ft_change_status(tmp, philoid);
			tmp = forks;
			tmp = ft_change_status(tmp, philoid);
		}
	}
}
