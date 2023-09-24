/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:06:28 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 09:03:11 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include "typedef.h"

size_t		ft_strlen(const char *s);
bool		ft_isdigit(int c);
int			ft_atoi(char *str, bool *has_non_digit_char);
int			*check_argv_validation(int argc, char **argv, int *args);
bool		is_argv_valid(int argc, char **argv, int **args);
int			create_all_threads(t_data *data);
int			join_all_threads(t_data data);
void		update_data_init_philo(t_data *data, int i);
void		init_data(t_data *data, int *converted_args, int argc);
void		free_all(t_data data, int *converted_args);
void		*routine(void *param);
void		handle_total_even_philos(t_philo *philo, bool is_philo_index_odd);
void		handle_total_odd_philos(t_philo *philo, bool is_philo_index_odd);
int			create_all_mutexes(t_data *data);
int			destroy_all_mutexes(t_data data);
long int	get_current_time(void);
long int	get_relative_time(t_data *data);
void		msleep_accu(int time_span);
void		do_action(t_philo *philo, long int *time, t_action action);
void		philo_even_take_both_forks(t_philo *philo, long int *time);
void		philo_odd_take_both_forks(t_philo *philo, long int *time);
void		philo_put_both_forks_back(t_philo *philo);
void		*monitor_num_each_philo_eat(void	*param);
void		*monitor_philo_death(void *param);
int			is_finished_flag_raised_by_other_threads(t_data *data);
void		raise_is_finished_flag(t_data *data);
void		print_message(t_philo *philo, long int time, const char *message);
#endif
