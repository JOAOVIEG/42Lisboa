/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:45:27 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/04 18:10:34 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	so_long(char *file)
{
	t_win	*game;
	
	if (check_file_ext(file) == 0)
		game = (t_win *)malloc(sizeof(t_win));
	game_build(file, game);
	shut_game_down(game);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
    if (ac == 2 && *av[1])
		so_long(av[1]);
	else
		game_error_msg("Error\nWrong number of arguments\n", NULL);
	return (0);
}