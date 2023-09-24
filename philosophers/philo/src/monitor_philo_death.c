/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philo_death.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:16:31 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 08:41:49 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_a_philo_dead(t_data *data, int i)
{
	int			time_to_die;
	long int	current_relative_time;

	time_to_die = data->time_to_die;
	current_relative_time = get_relative_time(data);
	pthread_mutex_lock(data->mutex_last_eat);
	if (current_relative_time - (data->philos + i)->last_eat_time > time_to_die)
	{
		pthread_mutex_unlock(data->mutex_last_eat);
		print_message((data->philos + i), get_relative_time(data), "died");
		raise_is_finished_flag(data);
		return (TRUE);
	}
	pthread_mutex_unlock(data->mutex_last_eat);
	return (FALSE);
}

void	*monitor_philo_death(void *param)
{
	t_data	*data;
	int		i;

	data = (t_data *)param;
	while (TRUE)
	{
		i = 0;
		while (i < data->philos_num)
		{
			if (is_a_philo_dead(data, i))
				return (NULL);
			i++;
		}
		if (is_finished_flag_raised_by_other_threads(data))
			return (NULL);
	}
	return (NULL);
}
