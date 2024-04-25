/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:12:38 by joaocard          #+#    #+#             */
/*   Updated: 2024/04/25 14:36:35 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_atol(const char *av)
{
	int		sign;
	size_t	integer;

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

int	parse_args(t_table *table, char **av)
{
	table->nbr_philos = ft_atol(av[1]);
	if (table->nbr_philos < 1)
		return (printf("Wrong input: Required at least 1 philo\n"));
	table->time_to_die = ft_atol(av[2]) * 1e3;
	table->time_to_eat = ft_atol(av[3]) * 1e3;
	table->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (table->time_to_die < 60e3 || table->time_to_eat < 60e3
								||table->time_to_sleep < 60e3)
			return (printf("Wrong input: time has to more than 60 ms\n"));				
	if (av[5])
		table->nb_times_must_eat = ft_atol(av[5]);
	else
		table->nb_times_must_eat = -1;
	return (0);
}

int	philo_init(t_table *table)
{
	t_philo *philo;
	int		pos;

	pos = 0;
	while ( pos < table->nbr_philos)
	{
		philo = &table->philos[pos];
		philo->id = pos + 1;
		philo->meals_count = 0;
		philo->full = false;
		if (pthread_mutex_init(&philo->philo_lock, NULL) != 0)
			return (printf("ERROR initializing philo_lock"));
		philo->table = table;
		give_forks(philo, table->forks, pos);
		pos++;
	}
	return (0);
}

void	give_forks(t_philo *philo, t_fork *forks, int pos)
{
	size_t	nbr_forks;

	nbr_forks = philo->table->nbr_philos;
	if (philo->id % 2 == 0)
	{
		philo->prio_fork = &forks[pos];
		philo->sec_fork = &forks[(pos + 1) % nbr_forks];
	}
	else if (philo->id % 2)
	{
		philo->prio_fork = &forks[(pos + 1) % nbr_forks];
		philo->sec_fork = &forks[pos];
	}
}

int	init_table(t_table	*table)
{
	int i;

	i = 0;
	table->dinner_end = false;
	table->dinner_is_synchro = false;
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->nbr_philos);
	if (table->philos == NULL)
		return (printf("Error initializing with malloc, philos array"));
	table->forks = (t_fork *)malloc(sizeof(t_fork) * table->nbr_philos);
	if (table->forks == NULL)
		return (printf("Error initializing with malloc forks array"));
	while (i < table->nbr_philos)
	{
		if (pthread_mutex_init(&table->forks[i].lock, NULL) != 0)
			return (printf("Error initializing with mutex, forks lock array"));
		i++;
	}
	if (pthread_mutex_init(&table->dinner_lock, NULL) != 0)
		return (printf("Error initializing with mutex, sim_mutex"));
	if (pthread_mutex_init(&table->print_lock, NULL) != 0)
		return (printf("Error initializing with mutex, print_mutex"));
	if (philo_init(table) != 0)
		return (printf("Error with philo initialization\n"));
	return (0);
}

