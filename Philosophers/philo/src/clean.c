/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:25:01 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/02/08 20:19:45 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_philo	*ft_free_philo(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	if (!tmp)
		return (NULL);
	while (tmp->next)
	{
		if (tmp)
		{
			if (tmp->checker_mutex)
				free(tmp->checker_mutex);
			free(tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_fork	*ft_free_forks(t_fork *fork)
{
	t_fork	*tmp;

	tmp = fork;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		pthread_mutex_destroy(&tmp->mutex);
		tmp = tmp->next;
		if (fork)
			free(fork);
		fork = tmp;
	}
	return (NULL);
}

t_data	ft_clean_data(t_data data)
{
	if (data.forks && data.philos)
	{
		data.forks = ft_free_forks(data.forks);
		data.philos = ft_free_philo(data.philos);
	}
	return (data);
}
