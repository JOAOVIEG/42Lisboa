/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:50:10 by joaocard          #+#    #+#             */
/*   Updated: 2024/05/19 21:08:19 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_usleep(long time, t_table *table)
{
	long	start;
	long	delta_t;
	long	remaining;

	start = gettimeofday_ms() * 1000;
	while ((gettimeofday_ms() * 1000) - start < time)
	{
		if (get_dinner_state(&table->dinner_lock, &table->dinner_end) == true)
			break ;
		delta_t = (gettimeofday_ms() * 1000) - start;
		remaining  = time - delta_t;
		if (remaining > 10000)
			usleep(remaining / 2);
		else
		{
			while (((gettimeofday_ms() * 1000) - start) < time)
				;
		}
	}
}

long	gettimeofday_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (printf("Error\n gettimeofday()\n"));
	else
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
