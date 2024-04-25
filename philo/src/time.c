/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:50:10 by joaocard          #+#    #+#             */
/*   Updated: 2024/04/24 14:43:07 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(size_t start)
{
	struct timeval	tv;
	size_t			current_time;

	if (gettimeofday(&tv, NULL) != 0)
		printf("Error\n gettimeofday()\n");
	else
		current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (current_time - start);
}

size_t	gettimeofday_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (printf("Error\n gettimeofday()\n"));
	else
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
