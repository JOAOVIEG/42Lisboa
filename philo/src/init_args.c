/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:12:38 by joaocard          #+#    #+#             */
/*   Updated: 2024/02/22 16:23:52 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*get_forks(t_philo_data *meal)
{
	t_fork	*forks;
	int	n;
	
	if (!(forks = malloc(sizeof(t_fork) * meal->number_of_philosophers)))
	{
		printf("Error malloc forks");
		return (NULL);
	}
	n = 0;
	while (n < meal->number_of_philosophers)
	{
		pthread_mutex_init(&forks[n].mutex, NULL);
		n++;
	}
	return (forks);
}

t_philo_data	*init_args(char **av)
{
	t_philo_data	*philo_data;
	
	if(!(philo_data = malloc(sizeof(t_philo_data))))
	{
		printf("Error malloc data");
		return (NULL);
	}
	philo_data->number_of_philosophers = ft_atol(av[1]);
	philo_data->time_to_die = ft_atol(av[2]);
	philo_data->time_to_eat = ft_atol(av[3]);
	philo_data->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		philo_data->nb_times_must_eat = ft_atol(av[5]);
	else
		philo_data->nb_times_must_eat = NULL;
	return (philo_data);
}

t_philo	*init_philos(t_philo_data *meal, t_fork *forks)
{
	t_philo *philo;
	int		n;
	
	if (!(philo = malloc(sizeof(t_philo) * meal->number_of_philosophers)))
	{
		printf("Error with philosophers! Check malloc");
		return (NULL);
	}
	n = 0;
	while (n < meal->number_of_philosophers)
	{
		philo[n].id = n + 1;
		if ((philo[n].last_meal = gettimeofday_ms()) == -1)
		{
			printf("ERROR getting last meal");
			//free_forks(forks)
			//free_meal()
			//free_philos()
			return (NULL);
		}
		philo[n].data = meal;
		philo[n].own_fork = &forks[n];
		philo[n].left_fork = &forks[(n + 1) % meal->number_of_philosophers];
 		n++;
	}
	return (philo);
}

void	init_dinner(t_philo *philo, t_philo_data *meal)
{
	int	n;

	n = 0;
	while (n < meal->number_of_philosophers)
	{
		if (pthread_create(&philo[n].thread, NULL, routine, &philo[n]) != 0)
		{
			printf("error with trhead number %d\n", n);
			return ;	
		}
		n++;
	}
	n = 0;
	while (n < meal->number_of_philosophers)
	{
		if (pthread_join(philo[n].thread, NULL) != 0)
		{
			printf("error joining trhead number %d\n", &n);
			return ;
		}
		n++;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int	current_time;
	int		optional;
	
	philo = arg;
	if (philo->data->nb_times_must_eat)
		optional = 0;
	else
		optional = 1;
	while ((philo->data->nb_times_must_eat && optional < philo->data->nb_times_must_eat) || (!(philo->data->nb_times_must_eat) && optional))
	{
		if (pthread_mutex_lock(&philo->own_fork->mutex) != 0)
		{
			printf("Error locking fork");
			return ;
		}
		current_time = gettimeofday_ms();
		printf("%d %d has taken a fork\n", current_time, philo->id);
		if (pthread_mutex_lock(&philo->left_fork->mutex) != 0)
		{
			printf("Error locking fork");
			return  ;
		}
		//EAT Action
		philo->last_meal = gettimeofday_ms();
		philo->state = EATING;
		printf("%d %d is eating\n", current_time, philo->id);
		usleep(philo->data->time_to_eat);
		//unlock mutexes
		if (pthread_mutex_unlock(&philo->own_fork->mutex) != 0)
		{
			printf("Error unlocking fork");
			return  ;
		}
		if (pthread_mutex_unlock(&philo->left_fork->mutex) != 0)
		{
			printf("Error unlocking fork");
			return  ;
		}
		//sleep
		current_time = gettimeofday_ms();
		philo->state = SLEEPING;
		printf("%d %d is sleeping\n", current_time, philo->id);
		usleep(philo->data->time_to_sleep);
		//think
		current_time = gettimeofday_ms();
		philo->state = THINKING;
		printf("%d %d is thinking\n", current_time, philo->id);
		// usleep(meal->time_to_die);
		if (philo->data->nb_times_must_eat)
			optional++;
	}
}

void	take_forks(t_philo *philo, t_fork *forks)
{
	int n;
	
	n = 0;
	while (n < philo->data->number_of_philosophers)
	{
		pthread_mutex_destroy(&philo[n].own_fork);
		pthread_mutex_destroy(&philo[n].left_fork);
		n++;
	}
	free_forks(forks);
}
