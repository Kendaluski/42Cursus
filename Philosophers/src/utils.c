/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:51:42 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/01/17 20:52:15 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
t_fork *ft_last(t_fork *list)
{
	t_fork *tmp;

	tmp = list;
	while(tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_print_list(t_philo *list)
{
	t_philo	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("Philosopher Number: %i\n{\n", tmp->id);
		printf("Left Philosopher: %i\n", tmp->id - 1);
		printf("Right Philosopher: %i\n", tmp->id + 1);
		printf("Times Eaten: %i\n", tmp->eat_count);
		printf("Actual status: %i\n}\n\n", tmp->status);
		tmp = tmp->next;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (!str || !str[i])
		return (-1);
	if (str[i] == '-')
		return (-1);
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}
