/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:30:39 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/01/31 17:38:31 by jjaen-mo         ###   ########.fr       */
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
	return (first);
}

void	*ft_philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->die_time == 0)
		return (NULL);
	while (philo->status != FINISHED)
	{
		if (ft_check_finish(philo) && philo->status == DEAD)
			ft_handle_death(philo);
		ft_philo_eat(philo);
		if (philo->max_eat != -1 && philo->eat_count == philo->max_eat)
		{
			philo->status = FINISHED;
			break ;
		}
		else
		{
			ft_philo_sleep(philo);
			ft_philo_think(philo);
		}
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
		philo->eat_time = data.eat_time;
		philo->sleep_time = data.sleep_time;
		philo->die_time = data.die_time;
		philo->eat_count = 0;
		philo->max_eat = data.max_eat;
		philo->status = 0;
		philo->last_eaten = 0;
		philo->first_fork = data.forks;
		philo->program_start = data.program_start;
		pthread_create(&philo->thread_id, NULL, ft_philo_life, philo);
		cnt++;
		philo->next = malloc(sizeof(t_philo));
		philo = philo->next;
	}
	return (first);
}

t_data	ft_init_data(char *num_philo, char *d_time, char *e_time, char *s_time)
{
	t_data	data;

	data.philo_num = ft_atoi(num_philo);
	if (data.philo_num == 1)
	{
		printf("There is only 1 philosopher,");
		printf("he will die because he can't eat\n");
		exit(0);
	}
	data.die_time = ft_atoi(d_time);
	data.eat_time = ft_atoi(e_time);
	data.sleep_time = ft_atoi(s_time);
	data.fork_num = data.philo_num;
	data.forks = ft_init_forks(data.fork_num);
	data.program_start = ft_start_time();
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
	if (argc == 5 || argc == 6)
	{
		data = ft_init_data(argv[1], argv[2], argv[3], argv[4]);
		if (argc == 6 && ft_atoi(argv[5]) > 0)
			data.max_eat = ft_atoi(argv[5]);
		else
			data.max_eat = -1;
		if (data.philo_num < 1 || data.die_time < 1 || data.eat_time < 1
			|| data.sleep_time < 1)
		{
			printf("[ERROR]: Negatives are not allowed!\n");
			return (1);
		}
		data.philos = ft_init_philos(data.philo_num, data);
		data.philos = ft_join_threads(data.philos);
		data = ft_clean_data(data);
	}
}
