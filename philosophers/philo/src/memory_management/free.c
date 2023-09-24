/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:13:15 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 08:29:26 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_data(t_data data)
{
	free(data.philos);
	free(data.philo_threads);
	free(data.monitor_death_thread);
	free(data.monitor_num_eat_thread);
	free(data.mutex_forks);
	free(data.mutex_time);
	free(data.mutex_num_eat);
	free(data.mutex_finish);
	free(data.mutex_print);
	free(data.mutex_last_eat);
	free(data.is_finished);
}

static void	free_converted_args(int *converted_args)
{
	free(converted_args);
}

void	free_all(t_data data, int *converted_args)
{
	free_data(data);
	free_converted_args(converted_args);
}
