/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/06 21:24:02 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_checks(t_win *game)
{
	if (!is_rectangular(game->file_map, game->map.height, game->map.width))
		game_error_msg("Error\nMap is not rectangular\n", game);
    if (!is_closed(game->file_map, game->map.height, game->map.width))
		game_error_msg("Error\nMap has invalid boundaries\n", game);
	if (!is_valid_chars(game->file_map, game->map.height, game->map.width))
		game_error_msg("Error\nMap has invalid characters\n", game);
	if (check_nbr_chrs(game->file_map, game->map.height, game->map.width) != 0)
	{
		if (check_nbr_chrs(game->file_map, game->map.height, game->map.width) == 1)
			game_error_msg("Error\nMap has no player\n", game);
		else if (check_nbr_chrs(game->file_map, game->map.height, game->map.width) == 2)
			game_error_msg("Error\nMap has no exit\n", game);
		else if (check_nbr_chrs(game->file_map, game->map.height, game->map.width) == 3)
			game_error_msg("Error\nMap has no collectibles\n", game);	
	}
	if (!check_duplicate_char(game->file_map, game->map.height, game->map.width))
		game_error_msg("Error\nMap has duplicate characters\n", game);
	if (!check_path(game->file_map, game->map.height, game->map.width))
		game_error_msg("Error\nMap has no possible path\n", game);
	return (0);
}

int	is_rectangular(char **map, int height, int width)
{
    int i;

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
	int i;

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
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicate_char(char **map, int height, int width)
{
	int exit;
	int player;

	exit = count_exit(map, height, width);
	player = count_player(map, height, width);
	if (exit > 1 || player > 1)
		return (0);
	return (1);
}

int check_nbr_chrs(char **map, int height, int width)
{
	if (count_player(map, height, width) == 0)
		return (1);
	else if (count_exit(map, height, width) == 0)
		return (2);
	else if (count_exit(map, height, width) == 0)
		return (3);
	return (0);
}

int	count_exit(char **map, int height, int width)
{
	int i;
	int j;
	int exit;
	
	i = 0;
	exit = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	return (exit);
}

int	count_player(char **map, int height, int width)
{
	int i;
	int j;
	int player;
	
	i = 0;
	player = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	return (player);
}

int	count_collectibles(char **map, int height, int width)
{
	int i;
	int j;
	int collectible;
	
	i = 0;
	collectible = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'E')
				collectible++;
			j++;
		}
		i++;
	}
	return (collectible);
}

int	check_path(char **map, int height, int width)
{
	t_pos player;
	t_pos exit;
	t_pos_list *collectibles;
	
	player = get_player_pos(map, height, width);
	exit = get_exit_pos(map, height, width);
	collectibles = get_collectible_pos(map, height, width);
	
}

t_pos	get_player_pos(char **map, int height, int width)
{
	int i;
	int j;
	t_pos pos;
	
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

t_pos	get_exit_pos(char **map, int height, int width)
{
	int i;
	int j;
	t_pos pos;
	
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'E')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

t_pos_list	*get_collectible_pos(char **map, int height, int width)
{
	t_pos_list *collectibles;
	t_pos_list *tmp;

	collectibles = NULL;
	int i;
	int j;
	
	i = 0;
	while (i++ < height)
	{
		j = 0;
		while (j++ < width)
		{
			if (map[i][j] == 'C')
			{
				tmp = (t_pos_list *)malloc(sizeof(t_pos_list));
				tmp->pos.x = j;
				tmp->pos.y = i;
				tmp->next = collectibles;
				collectibles = tmp;
			}
		}
	}
	return (collectibles);
}