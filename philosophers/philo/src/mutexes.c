/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:48:13 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 08:43:23 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(pthread_mutex_t *mutex, int mutex_num)
{
	int	i;

	i = 0;
	while (i < mutex_num)
	{
		if (pthread_mutex_init(mutex + i, NULL) != 0)
		{
			write(2, "MUTEX_NOT_CREATED\n", ft_strlen("MUTEX_NOT_CREATED\n"));
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	destroy_mutex(pthread_mutex_t *mutex, int array_len)
{
	int	i;

	i = 0;
	while (i < array_len)
	{
		if (pthread_mutex_destroy(mutex + i) != 0)
		{
			write(2, "MUTEX_NOT_DESTROYED\n", ft_strlen("MUTEX_NOT_DESTROYED\n"));
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	create_all_mutexes(t_data *data)
{
	if (!init_mutex(data->mutex_forks, data->philos_num))
		return (FALSE);
	if (!init_mutex(data->mutex_time, 1))
		return (FALSE);
	if (!init_mutex(data->mutex_num_eat, 1))
		return (FALSE);
	if (!init_mutex(data->mutex_last_eat, 1))
		return (FALSE);
	if (!init_mutex(data->mutex_finish, 1))
		return (FALSE);
	if (!init_mutex(data->mutex_print, 1))
		return (FALSE);
	return (TRUE);
}

int	destroy_all_mutexes(t_data data)
{
	if (!destroy_mutex(data.mutex_forks, data.philos_num))
		return (FALSE);
	if (!destroy_mutex(data.mutex_time, 1))
		return (FALSE);
	if (!destroy_mutex(data.mutex_num_eat, 1))
		return (FALSE);
	if (!destroy_mutex(data.mutex_last_eat, 1))
		return (FALSE);
	if (!destroy_mutex(data.mutex_finish, 1))
		return (FALSE);
	if (!destroy_mutex(data.mutex_print, 1))
		return (FALSE);
	return (TRUE);
}
