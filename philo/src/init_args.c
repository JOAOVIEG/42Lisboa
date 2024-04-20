/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:12:38 by joaocard          #+#    #+#             */
/*   Updated: 2024/04/19 14:26:37 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*get_forks(t_input_info *info)
{
	t_fork	*forks;
	int	n;
	
	if (!(forks = malloc(sizeof(t_fork) * info->number_of_philosophers)))
	{
		printf("Error malloc forks");
		return (NULL);
	}
	n = 0;
	while (n < info->number_of_philosophers)
	{
		pthread_mutex_init(&forks[n].mutex, NULL);
		n++;
	}
	return (forks);
}

t_input_info	*init_args(char **av)
{
	t_input_info	*philo_data;
	
	if(!(philo_data = malloc(sizeof(t_input_info))))
	{
		printf("Error malloc data");
		return (NULL);
	}
	memset(philo_data, 0, sizeof(t_input_info));
	philo_data->number_of_philosophers = ft_atol(av[1]);
	philo_data->time_to_die = ft_atol(av[2]);
	philo_data->time_to_eat = ft_atol(av[3]);
	philo_data->time_to_sleep = ft_atol(av[4]);
	philo_data->start = gettimeofday_ms();
	if (av[5])
		philo_data->nb_times_must_eat = ft_atol(av[5]);
	philo_data->sim_end = false;
	pthread_mutex_init(&philo_data->sim_mutex, NULL);
	pthread_mutex_init(&philo_data->print_mutex, NULL);
	return (philo_data);
}

t_philo	*philos_data(t_input_info *info, t_fork *forks)
{
	t_philo *philos;
	int		n;
	
	if (!(philos = malloc(sizeof(t_philo) * info->number_of_philosophers)))
	{
		printf("Error with philosophers! Check malloc");
		return (NULL);
	}
	n = 0;
	while (n < info->number_of_philosophers)
	{
		memset(&philos[n], 0 , sizeof(t_philo));
		philos[n].id = n + 1;
		philos[n].last_meal = 0;
		philos[n].state = IS_SEATING;
		philos[n].philo_info = info;
		philos[n].own_fork = &forks[n];
		philos[n].left_fork = &forks[(n + 1) % info->number_of_philosophers];
 		n++;
	}
	return (philos);
}

void	init_dinner(t_philo *philos, t_input_info *info)
{
	int		n;
	t_philo	*arg;

	n = 0;
	while (n < info->number_of_philosophers)
	{
		arg = malloc(sizeof(t_philo));
		*arg = philos[n];
		if (pthread_create(&philos[n].thread, NULL, routine, arg))
		{
			printf("error with trhead number %d\n", n);
			return ;
		}
		if (pthread_create(&philos[n].monitor_th, NULL, monitor, arg))
		{
			printf("error with trhead number %d\n", n);
			return ;
		}
		n++;
	}
	n = 0;
	while (n < info->number_of_philosophers)
	{
		if (pthread_join(philos[n].thread, NULL) != 0)
		{
			printf("error joining trhead number %d\n", n);
			return ;
		}
		if (pthread_join(philos[n].monitor_th, NULL) != 0)
		{
			printf("error joining trhead number %d\n", n);
			return ;
		}
		n++;
	}
}

void	*routine(void *arg)
{
	size_t	current_time;
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if(pthread_mutex_lock(&philo->philo_info->sim_mutex) == 0)
		{
			if (philo->philo_info->sim_end == true)
			{
				pthread_mutex_unlock(&philo->philo_info->sim_mutex);
				break ;
			}
			pthread_mutex_unlock(&philo->philo_info->sim_mutex);
		}
		if (((philo->state == THINKING) && pthread_mutex_lock(&philo->own_fork->mutex) == 0) || ((philo->state == IS_SEATING) && pthread_mutex_lock(&philo->own_fork->mutex) == 0))
		{
			current_time = get_current_time(philo->philo_info->start);
			pthread_mutex_lock(&philo->philo_info->print_mutex);
			printf("%ld %d has taken a fork\n", philo->last_meal, philo->id);
			pthread_mutex_unlock(&philo->philo_info->print_mutex);
			if (pthread_mutex_lock(&philo->left_fork->mutex) == 0)
			{
				if(pthread_mutex_lock(&philo->philo_info->sim_mutex) == 0)
				{
					/*Eating routine*/
					philo->last_meal = get_current_time(philo->philo_info->start);
					pthread_mutex_lock(&philo->philo_info->print_mutex);
					printf("%ld %d is eating\n", philo->last_meal, philo->id);
					pthread_mutex_unlock(&philo->philo_info->print_mutex);
					usleep(philo->philo_info->time_to_eat * 1000);
					pthread_mutex_unlock(&philo->own_fork->mutex);
					pthread_mutex_unlock(&philo->left_fork->mutex);
					/*Sleeping routine*/
					current_time = get_current_time(philo->philo_info->start);
					pthread_mutex_lock(&philo->philo_info->print_mutex);
					printf("%ld %d is sleeping\n", current_time, philo->id);
					pthread_mutex_unlock(&philo->philo_info->print_mutex);
					usleep(philo->philo_info->time_to_sleep * 1000);
					/*thinking routine*/
					current_time = get_current_time(philo->philo_info->start);
					pthread_mutex_lock(&philo->philo_info->print_mutex);
					printf("%ld %d is thinking\n", current_time, philo->id);
					pthread_mutex_unlock(&philo->philo_info->print_mutex);
					pthread_mutex_unlock(&philo->philo_info->sim_mutex);
				}
			}
		}
	}
	free(philo);
	return (NULL);
}

void	*monitor(void *arg)
{
	size_t		current_time;
	t_philo		*philo;

	philo = (t_philo *)arg;
	while(1)
	{
		pthread_mutex_lock(&philo->philo_info->sim_mutex);
		current_time = get_current_time(philo->philo_info->start);
		if ((current_time - philo->last_meal) >= philo->philo_info->time_to_sleep)
			philo->state = THINKING;
		else if ((current_time -philo->last_meal) < philo->philo_info->time_to_sleep)
			philo->state = NOT_THINKING;
		else if ((current_time - philo->last_meal) > philo->philo_info->time_to_die)
		{
			philo->state = -1;
			pthread_mutex_lock(&philo->philo_info->print_mutex);
			printf("%ld %d died\n", current_time, philo->id);
			pthread_mutex_unlock(&philo->philo_info->print_mutex);
			philo->philo_info->sim_end = true;
			pthread_mutex_unlock(&philo->philo_info->sim_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->philo_info->sim_mutex);
		usleep(10000);
	}
	return (NULL);
}

void	take_forks(t_input_info *info, t_fork *forks)
{
	int n;
	
	n = 0;
	while (n < info->number_of_philosophers)
	{
		pthread_mutex_destroy(&forks->mutex);
		n++;
	}
	pthread_mutex_destroy(&info->sim_mutex);
	pthread_mutex_destroy(&info->print_mutex);
	free(forks);
	forks = NULL;
}
