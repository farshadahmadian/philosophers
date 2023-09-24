/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:06:19 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 09:25:55 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# define TRUE 1
# define FALSE 0

typedef enum s_action
{
	TAKE_A_FORK,
	EAT,
	SLEEP,
	THINK,
}	t_action;

typedef enum s_error
{
	NOT_VALID_ARGS = 1,
	MUTEX_NOT_INITIATED,
	MUTEX_NOT_DESTROYED,
	THREAD_NOT_CREATED,
	THREAD_NOT_JOINED,
}	t_error;

typedef struct s_philo
{
	int				philo_index;
	int				num_eat;
	bool			did_eat;
	long int		last_eat_time;
	bool			exception;
	bool			is_hungry;	
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	long int		start_time;
	pthread_t		*philo_threads;
	pthread_t		*monitor_num_eat_thread;
	pthread_t		*monitor_death_thread;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	*mutex_time;
	pthread_mutex_t	*mutex_num_eat;
	pthread_mutex_t	*mutex_last_eat;
	pthread_mutex_t	*mutex_finish;
	pthread_mutex_t	*mutex_print;
	t_philo			*philos;
	bool			*is_finished;
}	t_data;

#endif
