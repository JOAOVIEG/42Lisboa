/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:50:10 by joaocard          #+#    #+#             */
/*   Updated: 2024/05/13 14:58:51 by joaocard         ###   ########.fr       */
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

void	my_usleep(size_t time, t_table *table)
{
	size_t	start;
	size_t	elapsed;
	size_t	remaining;

	start = gettimeofday_ms();
	while (gettimeofday_ms() - start < time)
	{
		if (get_dinner_state(&table->dinner_lock, &table->dinner_end))
			break ;
		elapsed = gettimeofday_ms() - start;
		remaining  = time - elapsed;
		if (remaining > 1000)
			usleep(remaining / 2);
		else
		{
			while (gettimeofday_ms() - start < time)
				;
		}
	}
}

size_t	gettimeofday_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (printf("Error\n gettimeofday()\n"));
	else
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
