/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:17:25 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/11/27 21:05:52 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

enum				e_status
{
	THINKING,
	EATING,
	SLEEPING,
	FORK,
	DEAD,
};

typedef struct s_fork
{
	int id;
	int status;
	struct s_fork *next;
}				t_fork;

typedef struct s_philo
{
	int				id;
	int				left_id;
	int				right_id;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_count;
	int				max_eat;
	int				status;
	pthread_t		thread_id;
	struct s_philo	*next;
}					t_philo;

typedef struct s_data
{
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				max_eat;
	int				fork_num;
	t_philo			*philos;
}					t_data;

/**
 * @brief Initialices the Data structure
 * 
 * @param num_philo Number of philosophers
 * @param d_time Time to die
 * @param e_time Time to eat
 * @param s_time Time to sleep
 * @return t_data The data initialaized
 */
t_data				ft_init_data(char *num_philo, char *d_time, char *e_time,
						char *s_time);
/**
 * @brief Initialices the list of Philosophers
 * 
 * @param num The number of philosophers
 * @return t_philo* The pointer to the first philosopher
 */
t_philo				*ft_init_philos(int num, t_data data);

/**
 * @brief Transforms a string to an integer
 * 
 * @param str The string to transform
 * @return int The number transformed (-1 if error)
 */
int					ft_atoi(char *str);

/**
 * @brief Prints the list of philosophers
 * 
 * @param list The pointer to the first philosopher
 */
void				ft_print_list(t_philo *list);

/**
 * @brief Simulates the life of the philosopher
 * 
 * @param arg The pointer to the philosopher
 * @return void* The pointer to the philosopher
 */
void				*ft_philo_life(void *arg);

/**
 * @brief Joins the threads of the philosophers
 * 
 * @param list The pointer to the first philosopher
 * @return t_philo* The pointer to the first philosopher after joining threats
 */
t_philo				*ft_join_threads(t_philo *list);

#endif