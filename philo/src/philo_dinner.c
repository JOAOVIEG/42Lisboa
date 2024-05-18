/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:21:04 by joaocard          #+#    #+#             */
/*   Updated: 2024/05/18 15:47:21 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	sync_trheads(philo->table);
	set_last_meal(&philo->philo_lock, &philo->last_meal, gettimeofday_ms);
	if (pthread_mutex_lock(&philo->table->dinner_lock) != 0)
		printf("Error locking mutex\n");
	philo->table->nbr_threads_running++;
	if (pthread_mutex_unlock(&philo->table->dinner_lock) != 0)
		printf("Error unlocking mutex\n");
	sync_rout_start(philo);
	while (get_dinner_state(&philo->table->dinner_lock, philo->table->dinner_end) == false)
	{
		if (get_dinner_state(&philo->philo_lock, philo->full) == true)
			break;
		eating_routine(philo);
		print_status(philo, SLEEP);
		my_usleep(philo->table->time_to_sleep, philo->table);
		print_status(philo, THINK);
		thinking_routine(philo);
	}
}

void	sync_rout_start(t_philo *philo)
{
	if (philo->id % 2 != 0)
		thinking_routine(philo);
	else if (philo->id % 2 == 0)
		my_usleep(30000, philo->table);
}

void	set_dinner_state(pthread_mutex_t *mutex, bool *state, bool value)
{
	if (pthread_mutex_lock(mutex) != 0)
		return (printf("Unable to lock dinner_lock\n"));
	*state = value;
	if (pthread_mutex_unlock(mutex) != 0)
		return (printf("Unable to unlock dinner_lock\n"));
}

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
	set_dinner_state(&table->dinner_lock, &table->dinner_is_synchro, true);
	i = 0;
	while (i < table->nbr_philos)
	{
		if (pthread_join(&table->philos[i].thread_id, NULL) != 0)
			return (printf("ERROR joining thread for philo nr %d\n", i));
		i++;
	}
	set_dinner_state(&table->dinner_lock, &table->dinner_end, true);
	if (pthread_join(&table->monitor_th, NULL) != 0)
		return (printf("ERROR joining thread for monitor \n"));
	return (0);
}