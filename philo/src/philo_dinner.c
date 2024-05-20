/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:21:04 by joaocard          #+#    #+#             */
/*   Updated: 2024/05/19 21:01:19 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	sync_threads(philo->table);
	set_last_meal(&philo->philo_lock, &philo->last_meal, gettimeofday_ms());
	if (pthread_mutex_lock(&philo->table->dinner_lock) != 0)
		printf("Error locking mutex\n");
	philo->table->nbr_threads_running++;
	if (pthread_mutex_unlock(&philo->table->dinner_lock) != 0)
		printf("Error unlocking mutex\n");
	sync_rout_start(philo);
	while (get_dinner_state(&philo->table->dinner_lock, &philo->table->dinner_end) == false)
	{
		if (get_dinner_state(&philo->philo_lock, &philo->full) == true)
			break;
		eating_routine(philo);
		print_status(philo, SLEEP);
		my_usleep(philo->table->time_to_sleep, philo->table);
		print_status(philo, THINK);
		thinking_routine(philo);
	}
	return (NULL);
}

void	*dinner_for_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	sync_threads(philo->table);
	set_last_meal(&philo->philo_lock, &philo->last_meal, gettimeofday_ms());
	if (pthread_mutex_lock(&philo->table->dinner_lock) != 0)
		printf("Error locking mutex\n");
	philo->table->nbr_threads_running++;
	if (pthread_mutex_unlock(&philo->table->dinner_lock) != 0)
		printf("Error unlocking mutex\n");
	print_status(philo, TAKE_FORK_1);
	while (get_dinner_state(&philo->table->dinner_lock, &philo->table->dinner_end) == false)
		my_usleep(200, philo->table);
	return (NULL);
}

void	sync_rout_start(t_philo *philo)
{ 
	if (philo->table->nbr_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			my_usleep(30000, philo->table);
	}
	else
	{
		if (philo->id % 2)
			thinking_routine(philo);
	}
}

void	set_dinner_state(pthread_mutex_t *mutex, bool *state, bool value)
{
	if (pthread_mutex_lock(mutex) != 0)
	{
		printf("Unable to lock dinner_lock\n");
		return ;
	}
	*state = value;
	if (pthread_mutex_unlock(mutex) != 0)
	{
		printf("Unable to unlock dinner_lock\n");
		return ;
	}
}

int	dinner_init(t_table *table)
{
	size_t	i;

	i = 0;
	
	if (table->nb_times_must_eat == 0)
		return (1);
	else if (table->nbr_philos == 1)
	{
		if (pthread_create(&table->philos[0].thread_id, NULL, dinner_for_one, &table->philos[0]) != 0)
			return (printf("ERROR creating thread for philo nr %ld\n", i));
	}
	else
	{
		while (i < table->nbr_philos)
		{
			if (pthread_create(&table->philos[i].thread_id, NULL, dinner, &table->philos[i]) != 0)
				return (printf("ERROR creating thread for philo nr %ld\n", i));
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
		if (pthread_join(table->philos[i].thread_id, NULL) != 0)
			return (printf("ERROR joining thread for philo nr %ld\n", i));
		i++;
	}
	set_dinner_state(&table->dinner_lock, &table->dinner_end, true);
	if (pthread_join(table->monitor_th, NULL) != 0)
		return (printf("ERROR joining thread for monitor \n"));
	return (0);
}

void	clean_table(t_table *table)
{
	size_t	i;
	t_philo	*philo;
	i = 0;
	while (i < table->nbr_philos)
	{
		philo = table->philos + i;
		if (pthread_mutex_destroy(&table->forks[i].lock) != 0)
			printf("Error destroying mutex");
		if (pthread_mutex_destroy(&philo->philo_lock) != 0)
			printf("Error destroying mutex");
		i++;
	}
	if (pthread_mutex_destroy(&table->dinner_lock) != 0)
		printf("Error destroying mutex");
	if (pthread_mutex_destroy(&table->print_lock) != 0)
		printf("Error destroying mutex");
	free(table->forks);
	free(table->philos);
}
