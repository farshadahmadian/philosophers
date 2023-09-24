/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:41:25 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 08:35:32 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_odd_take_both_forks(t_philo *philo, long int *time)
{
	pthread_mutex_lock(philo->data->mutex_forks + philo->philo_index);
	do_action(philo, time, TAKE_A_FORK);
	pthread_mutex_lock(philo->data->mutex_forks + philo->philo_index - 1);
	do_action(philo, time, TAKE_A_FORK);
}

void	philo_even_take_both_forks(t_philo *philo, long int *time)
{
	int	philos_num;
	int	philo_index;

	philos_num = philo->data->philos_num;
	philo_index = philo->philo_index;
	if (philo_index == 0)
	{
		pthread_mutex_lock(philo->data->mutex_forks + ((philos_num) - 1));
		do_action(philo, time, TAKE_A_FORK);
	}
	else
	{
		pthread_mutex_lock(philo->data->mutex_forks + ((philo_index) - 1));
		do_action(philo, time, TAKE_A_FORK);
	}
	if (philos_num == 1)
	{
		pthread_mutex_unlock(philo->data->mutex_forks + philos_num - 1);
		msleep_accu(philo->data->time_to_die);
		return ;
	}
	pthread_mutex_lock(philo->data->mutex_forks + philo_index);
	do_action(philo, time, TAKE_A_FORK);
}

void	philo_put_both_forks_back(t_philo *philo)
{
	int	philos_num;
	int	philo_index;

	philos_num = philo->data->philos_num;
	philo_index = philo->philo_index;
	if (philo_index == 0)
		pthread_mutex_unlock(philo->data->mutex_forks + philos_num - 1);
	else
		pthread_mutex_unlock(philo->data->mutex_forks + philo_index - 1);
	pthread_mutex_unlock(philo->data->mutex_forks + philo_index);
}

void	do_action(t_philo *philo, long int *time, t_action action)
{
	if (is_finished_flag_raised_by_other_threads(philo->data))
		return ;
	pthread_mutex_lock(philo->data->mutex_time);
	*time = get_relative_time(philo->data);
	if (action == TAKE_A_FORK)
		print_message(philo, *time, "has taken a fork");
	else if (action == EAT)
	{
		print_message(philo, *time, "is eating");
		pthread_mutex_lock(philo->data->mutex_num_eat);
		philo->num_eat++;
		pthread_mutex_unlock(philo->data->mutex_num_eat);
		pthread_mutex_lock(philo->data->mutex_last_eat);
		philo->last_eat_time = *time;
		pthread_mutex_unlock(philo->data->mutex_last_eat);
	}
	else if (action == SLEEP)
		print_message(philo, *time, "is sleeping");
	else if (action == THINK)
		print_message(philo, *time, "is thinking");
	pthread_mutex_unlock(philo->data->mutex_time);
	if (action == EAT)
		msleep_accu(philo->data->time_to_eat);
	else if (action == SLEEP)
		msleep_accu(philo->data->time_to_sleep);
}
