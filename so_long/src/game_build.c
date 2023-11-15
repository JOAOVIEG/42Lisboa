/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:37:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/14 16:18:43 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_build(char *file, t_win *game)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		game_error_msg("Error\nOpening file\n", NULL);
	read_map(fd, game);
	map_checks(game);
	game_init(game);
}

int	check_file_ext(char *file)
{
	char	*extension;

	extension = ft_strrchr(file, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0)
	{
		game_error_msg("Error\nWrong file extension\n", NULL);
		exit(EXIT_FAILURE);
	}
	return (0);
}
