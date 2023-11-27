/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:51:42 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/27 20:21:31 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_philo *ft_join_threads(t_philo *list)
{
	t_philo *tmp;

	tmp = list;
	while(tmp)
	{
		pthread_join(tmp->thread_id, NULL);
		tmp = tmp->next;
	}
	return (list);
}

void	ft_print_list(t_philo *list)
{
	t_philo	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("Philosopher Number: %i\n{\n", tmp->id);
		printf("Left Philosopher: %i\n", tmp->left_id);
		printf("Right Philosopher: %i\n", tmp->right_id);
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
