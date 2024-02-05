/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:30:39 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/02/05 23:30:57 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*ft_philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->die_time == 0)
		return (NULL);
	while (ft_check_exit(philo) != 1)
	{
		ft_philo_eat(philo);
		if (philo->max_eat != -1 && philo->eat_count == philo->max_eat)
		{
			philo->status = FINISHED;
			break ;
		}
		else if (ft_check_exit(philo) != 1)
		{
			ft_philo_sleep(philo);
			ft_philo_think(philo);
		}
	}
	return (NULL);
}

t_philo	*ft_init_philos(int num, t_data *data)
{
	t_philo	*first;
	t_philo	*philo;
	int		cnt;

	cnt = 0;
	first = malloc(sizeof(t_philo));
	philo = first;
	while (cnt < num)
	{
		philo = ft_philo_values(data, cnt, philo);
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
	data.exit = 0;
	pthread_mutex_init(&data.exit_mutex, NULL);
	return (data);
}

void	ft_philo_checker(t_data *data)
{
	while (1)
	{
		data->exit = ft_check_eat(data->philos, data->max_eat, data->philo_num);
		if (data->exit == 1)
			break ;
		data->exit = ft_handle_death(data->philos);
		if (data->exit == 1)
			break ;
	}
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
		data.philos = ft_init_philos(data.philo_num, &data);
		ft_philo_checker(&data);
		data.philos = ft_join_threads(data.philos);
		data = ft_clean_data(data);
	}
}
