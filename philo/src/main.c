/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:55:29 by joaocard          #+#    #+#             */
/*   Updated: 2024/04/18 15:26:41 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_input_info	*info;
	t_fork			*forks;
	t_philo			*philos;
	
	if (ac < 5 || ac > 6)
		return (printf("Wrong number of arguments\n"));
	if (!(info = init_args(av)))
		return (printf("Arg init error\n"));
	if (!(forks = get_forks(info)))
		return (printf("Forks init error\n"));
	if (!(philos = philos_data(info, forks)))
		return (printf("Philos init error\n"));
	init_dinner(philos, info);
	take_forks(info, forks);
	free(info);
	info = NULL;
	free(philos);
	philos = NULL;
	return (0);
}