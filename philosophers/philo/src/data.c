/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:44:58 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 08:36:25 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, int *converted_args, int argc)
{
	data->philos_num = converted_args[0];
	data->time_to_die = *(converted_args + 1);
	data->time_to_eat = *(converted_args + 2);
	data->time_to_sleep = converted_args[3];
	if (argc == 6)
		data->num_must_eat = converted_args[4];
	else
		data->num_must_eat = -1;
	data->start_time = get_current_time();
	data->philo_threads = malloc(data->philos_num * sizeof(pthread_t));
	data->monitor_num_eat_thread = malloc(sizeof(pthread_t));
	data->monitor_death_thread = malloc(sizeof(pthread_t));
	data->mutex_forks = malloc(data->philos_num * sizeof(pthread_mutex_t));
	data->mutex_time = malloc(sizeof(pthread_mutex_t));
	data->mutex_num_eat = malloc(sizeof(pthread_mutex_t));
	data->mutex_finish = malloc(sizeof(pthread_mutex_t));
	data->mutex_print = malloc(sizeof(pthread_mutex_t));
	data->mutex_last_eat = malloc(sizeof(pthread_mutex_t));
	data->philos = malloc(data->philos_num * sizeof(t_philo));
	data->is_finished = malloc(sizeof(bool));
	*(data->is_finished) = FALSE;
}

void	update_data_init_philo(t_data *data, int i)
{
	data->philos[i].philo_index = i;
	pthread_mutex_lock(data->mutex_num_eat);
	data->philos[i].num_eat = 0;
	data->philos[i].last_eat_time = 0;
	pthread_mutex_unlock(data->mutex_num_eat);
	(data->philos + i)->did_eat = false;
	(data->philos + i)->data = data;
	(data->philos + i)->exception = FALSE;
	if ((data->philos + i)->philo_index % 2 == 0)
		(data->philos + i)->is_hungry = FALSE;
	else
		(data->philos + i)->is_hungry = TRUE;
}
