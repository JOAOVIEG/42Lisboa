/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:45:27 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/26 16:45:03 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	so_long(char *file)
{
	t_win	*game;

	if (check_file_ext(file) == 0 && (open(file, O_RDONLY)) != -1)
	{
		game = (t_win *)malloc(sizeof(t_win));
		if (game == NULL)
			game_error_msg("Error\nMalloc\n", NULL);
		start(game);
		game_build(file, game);
	}
	else if ((open(file, O_RDONLY)) == -1)
	{
		game_error_msg("Error\nOpening file\n", NULL);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2 && *av[1])
		so_long(av[1]);
	else
		game_error_msg("Error\nWrong number of arguments\n", NULL);
	return (0);
}
