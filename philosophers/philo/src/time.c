/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:06:09 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 09:29:59 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_current_time(void)
{
	struct timeval	time;
	long int		epoch_ms;

	gettimeofday(&time, NULL);
	epoch_ms = (time.tv_sec * 1000) + (long int)(time.tv_usec / 1000);
	return (epoch_ms);
}

long int	get_relative_time(t_data *data)
{
	long	relative_time;

	relative_time = get_current_time() - data->start_time;
	return (relative_time);
}

void	msleep_accu(int time_span)
{
	long int	time1;
	long int	time2;

	time1 = get_current_time();
	time2 = get_current_time();
	while (time2 - time1 < time_span)
	{
		usleep(10);
		time2 = get_current_time();
	}
}
