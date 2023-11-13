/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/13 16:23:55 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

int	is_rectangular(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (ft_strlen(map[i]) != (size_t)width)
			return (0);
		i++;
	}
	return (1);
}

int	is_closed(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_chars(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' \
								&& map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicate_char(char **map, int height, int width)
{
	int	exit;
	int	player;

	exit = count_exit(map, height, width);
	player = count_player(map, height, width);
	if (exit > 1 || player > 1)
		return (0);
	return (1);
}
