/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:38:33 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 08:45:09 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		data;
	int			*converted_args;

	if (!is_argv_valid(argc, argv, &converted_args))
	{
		write(2, "Invalid Arguments\n", ft_strlen("Invalid Arguments\n"));
		return (NOT_VALID_ARGS);
	}
	init_data(&data, converted_args, argc);
	if (!create_all_mutexes(&data))
		return (MUTEX_NOT_INITIATED);
	if (!create_all_threads(&data))
		return (THREAD_NOT_CREATED);
	if (!join_all_threads(data))
		return (THREAD_NOT_JOINED);
	if (!destroy_all_mutexes(data))
		return (MUTEX_NOT_DESTROYED);
	free_all(data, converted_args);
	return (0);
}
