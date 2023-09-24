/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_even_philos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:47:06 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 09:01:07 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	routine_even_philos_total_even(t_philo *philo)
{
	long int	time;

	do_action(philo, &time, SLEEP);
	do_action(philo, &time, THINK);
	philo_even_take_both_forks(philo, &time);
	do_action(philo, &time, EAT);
	philo_put_both_forks_back(philo);
}

static void	routine_odd_philos_total_even(t_philo *philo)
{
	long int	time;

	philo_odd_take_both_forks(philo, &time);
	do_action(philo, &time, EAT);
	philo_put_both_forks_back(philo);
	do_action(philo, &time, SLEEP);
	do_action(philo, &time, THINK);
}

void	handle_total_even_philos(t_philo *philo, bool is_philo_index_odd)
{
	if (is_philo_index_odd)
	{
		routine_odd_philos_total_even(philo);
	}
	else if (!is_philo_index_odd)
	{
		routine_even_philos_total_even(philo);
	}
}
