/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:06:03 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 08:31:13 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*check_argv_validation(int argc, char **argv, int *converted_args)
{
	int		i;
	int		num;
	bool	has_non_digit_cahr;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i], &has_non_digit_cahr);
		if (has_non_digit_cahr)
			return (NULL);
		if (num > 0)
			converted_args[i - 1] = num;
		else
			return (NULL);
		i++;
	}
	if (converted_args[0] > 200 || converted_args[1] < 60
		|| converted_args[2] < 60 || converted_args[3] < 60)
		return (NULL);
	return (converted_args);
}

bool	is_argv_valid(int argc, char **argv, int **converted_args)
{
	if (argc < 5 || argc > 6)
		return (FALSE);
	*converted_args = malloc((argc - 1) * sizeof(int));
	if (!(*converted_args))
		return (FALSE);
	if (!check_argv_validation(argc, argv, *converted_args))
	{
		free (*converted_args);
		return (FALSE);
	}
	return (TRUE);
}
