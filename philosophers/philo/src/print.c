/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 08:34:13 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/26 10:44:14 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, long int time, const char *message)
{
	pthread_mutex_lock(philo->data->mutex_print);
	pthread_mutex_lock(philo->data->mutex_finish);
	if (!*(philo->data->is_finished))
		printf("%ld %d %s\n", time, philo->philo_index + 1, message);
	pthread_mutex_unlock(philo->data->mutex_finish);
	pthread_mutex_unlock(philo->data->mutex_print);
}
