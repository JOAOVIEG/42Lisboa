/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:21:04 by joaocard          #+#    #+#             */
/*   Updated: 2024/04/25 15:21:49 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dinner_init(t_table *table)
{
	int	i;

	i = 0;
	if (table->nbr_philos == 0)
	{
		/*have to do this for one philo*/
	}
	else
	{
		while (i < table->nbr_philos)
		{
			if (pthread_create(&table->philos[i].thread_id, NULL, dinner, &table->philos[i]) != 0)
				return (printf("ERROR creating thread for philo nr %d\n", i));
			i++;
		}
	}
	if (pthread_create(&table->monitor_th, NULL, monitor, table) != 0)
				return (printf("ERROR creating thread for monitor\n"));
	table->start = gettimeofday_ms();
	if (pthread_mutex_lock(&table->dinner_lock) != 0)
		return (printf("Unable to lock dinner_lock\n"));
	table->dinner_is_synchro = true;
	if (pthread_mutex_unlock(&table->dinner_lock) != 0)
		return (printf("Unable to unlock dinner_lock\n"));
	i = 0;
	while (i < table->nbr_philos)
	{
		if (pthread_join(&table->philos[i].thread_id, NULL) != 0)
			return (printf("ERROR joining thread for philo nr %d\n", i));
		i++;
	}
	if (pthread_mutex_lock(&table->dinner_lock) != 0)
		return (printf("Unable to lock dinner_lock\n"));
	table->dinner_end = true;
	if (pthread_mutex_unlock(&table->dinner_lock) != 0)
		return (printf("Unable to unlock dinner_lock\n"));

	if (pthread_join(&table->monitor_th, NULL) != 0)
		return (printf("ERROR joining thread for monitor \n"));
	return (0);
}
