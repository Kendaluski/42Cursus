/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:04:18 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/02/05 22:21:18 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_fork	*ft_init_forks(int forkn)
{
	int		cnt;
	t_fork	*first;
	t_fork	*fork;

	first = malloc(sizeof(t_fork));
	cnt = 0;
	fork = first;
	while (cnt < forkn)
	{
		fork->id = cnt + 1;
		fork->status = 0;
		fork->philo_id = 0;
		pthread_mutex_init(&fork->mutex, NULL);
		cnt++;
		fork->next = malloc(sizeof(t_fork));
		fork = fork->next;
	}
	fork->next = NULL;
	return (first);
}

t_philo	*ft_philo_values(t_data *data, int cnt, t_philo *philo)
{
	philo->id = cnt + 1;
	philo->eat_time = data->eat_time;
	philo->sleep_time = data->sleep_time;
	philo->die_time = data->die_time;
	philo->eat_count = 0;
	philo->max_eat = data->max_eat;
	philo->status = 0;
	philo->last_eaten = 0;
	philo->program_start = data->program_start;
	philo->data = data;
	philo->first_fork = philo->data->forks;
	philo->checker_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->checker_mutex, NULL);
	pthread_create(&philo->thread_id, NULL, ft_philo_life, philo);
	return (philo);
}
