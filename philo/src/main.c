/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:55:29 by joaocard          #+#    #+#             */
/*   Updated: 2024/05/19 16:09:02 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table		table;
	
	if (ac < 5 || ac > 6)
		return (printf("Wrong number of arguments\n"));
	else if (ac == 5 || ac == 6)
	{
		if (parse_args(&table, av) != 0)
			return (printf("Error parsing arguments\n"));
		if (init_table(&table) != 0)
			return (printf("Error initializing tavle\n"));
		if (dinner_init(&table) != 0)
			return (printf("Error initializing dinner\n"));
		clean_table(&table);
	}
	return (0);
}
