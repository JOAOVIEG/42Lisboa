/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:50:10 by joaocard          #+#    #+#             */
/*   Updated: 2024/02/22 10:50:54 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_atol(const char *av)
{
	int			sign;
	long int	integer;

	sign = 1;
	integer = 0;
	if (*(char *)av == '-' || *(char *)av == '+')
	{
		if (*(char *)av == '-')
			sign = -1;
		av++;
	}
	while (*(char *)av && *(char *)av >= '0' && *(char *)av <= '9')
	{
		integer = (integer * 10) + *(char *)av - '0';
		av++;
	}
	return (sign * integer);
}

int	gettimeofday_ms(void)
{
	struct timeval tv;
	
	if (gettimeofday(&tv, NULL) == 0)
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (-1);
}
