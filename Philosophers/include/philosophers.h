/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:17:25 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/01/31 17:38:39 by jjaen-mo         ###   ########.fr       */
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
	FINISHED
};

typedef struct s_fork
{
	int				id;
	int				status;
	int				philo_id;
	pthread_mutex_t	mutex;
	struct s_fork	*next;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				eat_time;
	int				sleep_time;
	int				eat_count;
	int				max_eat;
	int				die_time;
	int				status;
	long			last_eaten;
	long			program_start;
	pthread_t		thread_id;
	struct s_fork	*first_fork;
	struct s_philo	*next;
}					t_philo;

typedef struct s_data
{
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				max_eat;
	long			program_start;
	int				fork_num;
	t_philo			*philos;
	t_fork			*forks;
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

/**
 * @brief Check if the philosopher can pick a fork
 * 
 * @param forks The list of forks
 * @param philo The the philosopher
 * @param action The action to do (0 = unlock, 1 = lock)
 * @return int 1 if the philosopher can pick a fork, 0 if not
 */
void				ft_pick_forks(t_fork *forks, t_philo *philo, int action);

/**
 * @brief Returns the last fork of the list
 * 
 * @param list The list of forks
 * @return t_fork* The last fork of the list
 */
t_fork				*ft_last(t_fork *list);

/**
 * @brief Returns the start time of the program
 * 
 * @return long The start time of the program
 */
long				ft_start_time(void);

/**
 * @brief Returns the current time of the program (since the start of it)
 * 
 * @param start_time The start of the program
 * @return long The current time
 */
long				ft_current_time(long start_time);

/**
 * @brief Function that simulates the philosopher eating
 * 
 * @param philo The philosopher to simulate
 */
void				ft_philo_eat(t_philo *philo);

/**
 * @brief Function to simulate the philosopher sleeping
 * 
 * @param philo The philosopher to simulate
 */
void				ft_philo_sleep(t_philo *philo);

/**
 * @brief Function to simulate the philosopher thinking
 * 
 * @param philo The philosopher to simulate
 */
void				ft_philo_think(t_philo *philo);

/**
 * @brief Checks if the philosopher has died
 * 
 * @param philo The philosopher to check
 * @return int 1 if the philosopher has died, 0 if not
 */
int					ft_check_finish(t_philo *philo);

/**
 * @brief Cleans the data structure
 * 
 * @param data The data structure to clean
 * @return t_data The data structure cleaned
 */
t_data				ft_clean_data(t_data data);

/**
 * @brief Cleans the philosophers list
 * 
 * @param philo The first philosopher of the list
 * @return t_philo* NULL
 */
t_philo				*ft_free_philo(t_philo *philo);

/**
 * @brief Cleans the forks list
 * 
 * @param fork The firts fork of the list
 * @return t_fork* NULL
 */
t_fork				*ft_free_forks(t_fork *fork);

void ft_handle_death(t_philo *philo);

#endif