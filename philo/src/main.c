/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:55:29 by joaocard          #+#    #+#             */
/*   Updated: 2024/02/22 16:05:47 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo_data	*meal;
	t_fork			*forks;
	t_philo			*philos;
	
	if (ac < 5 || ac > 6)
		return (printf("Wrong number of arguments\n"));
	if (!(meal = init_args(av)))
		return (printf("Arg init error\n"));
	if (!(forks = get_forks(meal)));
	if (!(philos = init_philos(meal)))
		return (printf("Philos init error\n"));
	init_dinner(philos, meal);
	take_forks(meal, philos);
	return (0);
}