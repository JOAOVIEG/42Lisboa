/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:37:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/26 11:09:13 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	start(t_win *game)
{
	game->map.height = 0;
	game->map.width = 0;
	game->file_map = NULL;
	game->moves = 0;
}

void	game_build(char *file, t_win *game)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		game_error_msg("Error\nOpening file\n", NULL);
	read_map(fd, game);
	map_checks(game);
	game_loop(game);
}

void	read_map(int fd, t_win *game)
{
	char	*line;

	line = 0;
	game->file_map = (char **)malloc(sizeof(char *) * 1);
	if (!game->file_map)
		game_error_msg("Error\nMalloc\n", game);
	map_init(game, fd, line);
}

void	map_checks(t_win *game)
{
	if (!is_rectangular(game->file_map, game->map.height, game->map.width))
		game_error_msg("Error\nMap is not rectangular\n", game);
	if (!is_closed(game->file_map, game->map.height, game->map.width))
		game_error_msg("Error\nMap has invalid boundaries\n", game);
	if (!is_valid_chars(game->file_map, game->map.height, game->map.width))
		game_error_msg("Error\nMap has invalid characters\n", game);
	if (check_nbr_chrs(game->file_map, game->map.height, game->map.width) != 0)
		char_msg(check_nbr_chrs(game->file_map, game->map.height, \
												game->map.width), game);
	if (!check_duplicate_char(game->file_map, game->map.height, \
														game->map.width))
		game_error_msg("Error\nMap has duplicate characters\n", game);
	if (check_path_to_exit(game, game->map.height, game->map.width))
		game_error_msg("Error\nMap has no possible path\n", game);
}

void	map_init(t_win *game, int fd, char *line)
{
	game->map.width = 0;
	game->map.height = 0;
	copy_lines(game, fd, line);
	game->map.width = ft_strlen(game->file_map[0]);
}
