/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:45:27 by joaocard          #+#    #+#             */
/*   Updated: 2023/10/26 14:54:13 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	so_long(char *file)
{
	t_game	*game;
	
	game = (t_game *)malloc(sizeof(t_game));
	file_map_build(file, game);
	free(game);
	return (0);
}

int	main(int ac, char **av)
{
    if (ac ==2)
		return (so_long(av[1]));
	else
		ft_printf("Error\nWrong number of arguments\n");
	return (0);
}