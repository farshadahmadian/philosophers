/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:38:20 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 08:57:35 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_philo_threads(t_data *data)
{
	int			i;
	pthread_t	*philo_threads;
	t_philo		*philos;

	i = 0;
	philo_threads = data->philo_threads;
	philos = data->philos;
	while (i < data->philos_num)
	{
		update_data_init_philo(data, i);
		if (pthread_create(philo_threads + i, NULL, routine, philos + i) != 0)
		{
			write(2, "THREAD_NOT_CREATED\n", ft_strlen("THREAD_NOT_CREATED\n"));
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	create_all_threads(t_data *data)
{
	pthread_t	*num_eat;
	pthread_t	*death;

	num_eat = data->monitor_num_eat_thread;
	death = data->monitor_death_thread;
	if (!create_philo_threads(data))
		return (FALSE);
	if (pthread_create(num_eat, NULL, monitor_num_each_philo_eat, data) != 0)
		return (FALSE);
	if (pthread_create(death, NULL, monitor_philo_death, data) != 0)
		return (FALSE);
	return (TRUE);
}

static int	join_threads(t_data data)
{
	int	i;

	i = 0;
	while (i < data.philos_num)
	{
		if (pthread_join(data.philo_threads[i], NULL) != 0)
		{
			write(2, "THREAD_NOT_JOINED\n", ft_strlen("THREAD_NOT_JOINED\n"));
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	join_all_threads(t_data data)
{
	if (!join_threads(data))
		return (FALSE);
	if (pthread_join(*(data.monitor_num_eat_thread), NULL) != 0)
		return (FALSE);
	if (pthread_join(*(data.monitor_death_thread), NULL) != 0)
		return (FALSE);
	return (TRUE);
}
