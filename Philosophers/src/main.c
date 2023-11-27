/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:30:39 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/27 21:05:06 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*ft_philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		philo->status = THINKING;
		printf("Philosopher %i is thinking\n", philo->id);
		sleep(1);
		philo->status = FORK;
		printf("Philosopher %i has taken a fork\n", philo->id);
		philo->status = EATING;
		printf("Philosopher %i is eating\n", philo->id);
		sleep(philo->eat_time);
		philo->eat_count++;
		philo->status = SLEEPING;
		printf("Philosopher %i is sleeping\n", philo->id);
		sleep(philo->sleep_time);
	}
	return (NULL);
}

t_philo	*ft_init_philos(int num, t_data data)
{
	t_philo	*first;
	t_philo	*philo;
	int		cnt;

	cnt = 0;
	first = malloc(sizeof(t_philo));
	philo = first;
	while (cnt < num)
	{
		philo->id = cnt + 1;
		if (cnt == 0)
			philo->left_id = num;
		else
			philo->left_id = cnt;
		if (cnt == num - 1)
			philo->right_id = 1;
		else
			philo->right_id = cnt + 2;
		philo->eat_count = 0;
		philo->die_time = data.die_time;
		philo->eat_time = data.eat_time;
		philo->sleep_time = data.sleep_time;
		philo->max_eat = data.max_eat;
		philo->status = 0;
		pthread_create(&philo->thread_id, NULL, ft_philo_life, philo);
		philo->next = malloc(sizeof(t_philo));
		philo = philo->next;
		cnt++;
	}
	return (first);
}

t_data	ft_init_data(char *num_philo, char *d_time, char *e_time, char *s_time)
{
	t_data	data;

	data.philo_num = ft_atoi(num_philo);
	data.die_time = ft_atoi(d_time);
	data.eat_time = ft_atoi(e_time);
	data.sleep_time = ft_atoi(s_time);
	data.fork_num = data.philo_num;
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		printf("[ERROR]: Wrong argument input\n");
		return (1);
	}
	if (argc == 5)
	{
		data = ft_init_data(argv[1], argv[2], argv[3], argv[4]);
		if (data.philo_num < 1 || data.die_time < 1 || data.eat_time < 1
			|| data.sleep_time < 1)
		{
			printf("[ERROR]: Negatives are not allowed!\n");
			return (1);
		}
		data.philos = ft_init_philos(data.philo_num, data);
		data.philos = ft_join_threads(data.philos);
	}
}
