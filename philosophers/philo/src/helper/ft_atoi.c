/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:30:08 by fahmadia          #+#    #+#             */
/*   Updated: 2023/09/24 08:28:48 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*check_initial_white_space(char *str, int *sign)
{
	*sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\r' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

static bool	check_end_white_space(char *str, bool *has_non_digit_char)
{
	while (*str)
	{
		if (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f' || *str == ' ')
			str++;
		else
		{
			*has_non_digit_char = TRUE;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	ft_atoi(char *str, bool *has_non_digit_char)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	str = check_initial_white_space(str, &sign);
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	*has_non_digit_char = check_end_white_space(str, has_non_digit_char);
	if (sign == -1)
		num *= -1;
	return (num);
}	
