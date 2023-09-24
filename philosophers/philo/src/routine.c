/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:02:00 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 09:31:29 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *param)
{	
	t_philo		*philo;
	bool		is_philo_index_odd;

	philo = (t_philo *)param;
	is_philo_index_odd = philo->philo_index % 2 == 1;
	if (!(philo->data->philos_num % 2 == 1))
	{
		while (TRUE)
		{
			if (is_finished_flag_raised_by_other_threads(philo->data))
				return (NULL);
			handle_total_even_philos(philo, is_philo_index_odd);
		}
	}
	else
	{
		while (TRUE)
		{
			if (is_finished_flag_raised_by_other_threads(philo->data))
				return (NULL);
			handle_total_odd_philos(philo, is_philo_index_odd);
		}
	}
	return (NULL);
}
