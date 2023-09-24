/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:03:06 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 08:36:42 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_finished_flag_raised_by_other_threads(t_data *data)
{
	pthread_mutex_lock(data->mutex_finish);
	if (*(data->is_finished))
	{
		pthread_mutex_unlock(data->mutex_finish);
		return (TRUE);
	}
	pthread_mutex_unlock(data->mutex_finish);
	return (FALSE);
}

void	raise_is_finished_flag(t_data *data)
{
	pthread_mutex_lock(data->mutex_finish);
	*(data->is_finished) = TRUE;
	pthread_mutex_unlock(data->mutex_finish);
}
