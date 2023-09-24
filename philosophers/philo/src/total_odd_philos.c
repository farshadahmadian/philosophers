/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_odd_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:48:20 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 08:58:58 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_total_odd_philos(t_philo *philo, bool is_philo_odd)
{
	long int	time;

	if (philo->is_hungry)
	{
		if (is_philo_odd)
			philo_odd_take_both_forks(philo, &time);
		else if (!is_philo_odd)
		{
			philo_even_take_both_forks(philo, &time);
			if (philo->data->philos_num == 1)
				return ;
		}
		do_action(philo, &time, EAT);
		philo_put_both_forks_back(philo);
		do_action(philo, &time, SLEEP);
		do_action(philo, &time, THINK);
	}
	else if (!(philo->is_hungry))
	{
		do_action(philo, &time, SLEEP);
		do_action(philo, &time, THINK);
		philo->is_hungry = TRUE;
	}
}
