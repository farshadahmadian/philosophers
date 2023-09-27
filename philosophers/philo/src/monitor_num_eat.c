/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_num_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:46:29 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/27 08:32:10 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_all_philos_num_eat(t_data *data)
{
	int	i;
	int	num_of_philos_ate_enough_times;

	i = 0;
	num_of_philos_ate_enough_times = 0;
	if (data->num_must_eat == -1)
		return (num_of_philos_ate_enough_times);
	while (i < data->philos_num)
	{
		pthread_mutex_lock(data->mutex_num_eat + i);
		if ((data->philos + i)->num_eat >= data->num_must_eat)
			num_of_philos_ate_enough_times++;
		else
		{
			pthread_mutex_unlock(data->mutex_num_eat + i);
			return (num_of_philos_ate_enough_times);
		}
		pthread_mutex_unlock(data->mutex_num_eat + i);
		i++;
	}
	return (num_of_philos_ate_enough_times);
}

void	*monitor_num_each_philo_eat(void	*param)
{
	t_data	*data;
	int		num_of_philos_ate_enough_times;

	data = (t_data *)param;
	while (TRUE)
	{
		num_of_philos_ate_enough_times = check_all_philos_num_eat(data);
		usleep(100);
		if (num_of_philos_ate_enough_times == data->philos_num)
		{
			raise_is_finished_flag(data);
			return (NULL);
		}
		if (is_finished_flag_raised_by_other_threads(data))
			return (NULL);
	}
	return (NULL);
}
