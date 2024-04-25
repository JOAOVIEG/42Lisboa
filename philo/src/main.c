/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:55:29 by joaocard          #+#    #+#             */
/*   Updated: 2024/04/25 14:23:26 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table		table;
	
	if (ac < 5 || ac > 6)
		return (printf("Wrong number of arguments\n"));
	else
	{
		if (parse_args(&table, av) != 0)
			return (printf("Error parsing arguments\n"));
		if (init_table(&table) != 0)
			return (printf("Error initializing program\n"));
		dinner_init(&table);//TODO
		clean_table(&table);//TODO
	}
	return (0);
}