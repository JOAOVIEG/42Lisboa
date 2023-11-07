/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/07 20:18:14 by joaocard         ###   ########.fr       */
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
	if (check_path_to_exit(game, game->map.height, game->map.width))
		game_error_msg("Error\nMap has no possible path\n", game);
	if (!check_path_to_collectibles(game, game->map.height, game->map.width))
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

int	check_path_to_exit(t_win *game, int height, int width)
{
	t_pos 		player;
	t_pos 		exit;
	
	game->map_copy = copy_map(game);
	player = get_player_pos(game->map_copy, height, width);
	exit = get_exit_pos(game->map_copy, height, width);
	
	flood_fill(*game, player, exit);
	return (check_if_visited(*game, exit));
}

int	check_path_to_collectibles(t_win *game, int height, int width)
{
	t_pos 		player;
	t_pos_list	*collectibles;
	int 		result;
	game->map_copy = copy_map(game);
	player = get_player_pos(game->map_copy, height, width);
	collectibles = get_collectible_pos(game->map_copy, height, width);
	result = listed_flood_fill(*game, collectibles, player);

    // Free the memory allocated for collectibles
    t_pos_list *tmp;
    while (collectibles) {
        tmp = collectibles;
        collectibles = collectibles->next;
        free(tmp);
    }
	return (result);
}

char	**copy_map(t_win *game)
{
	int i;

	i = 0;
	game->map_copy = (char **)malloc(sizeof(char *) * game->map.height);
	if (!game->map_copy)
		game_error_msg("Error\nMalloc\n", game);
	while (i < game->map.height)
	{
		game->map_copy[i] = ft_strdup(game->file_map[i]);
		/*if (!game->map_copy)
			game_error_msg("Error\nMalloc\n", game);*/
		i++;
	}
	return (game->map_copy);
}

t_pos	get_player_pos(char **map, int height, int width)
{
	int i;
	int j;
	t_pos pos;
	
	i = 0;
	pos.x = 0;
	pos.y = 0;
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
	pos.x = 0;
	pos.y = 0;
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
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'C')
			{
				tmp = (t_pos_list *)malloc(sizeof(t_pos_list));
				tmp->pos.x = j;
				tmp->pos.y = i;
				tmp->next = collectibles;
				collectibles = tmp;
			}
			j++;
		}
		i++;
	}
	return (collectibles);
}

void free_pos_list(t_pos_list *list)
{
    t_pos_list *tmp;

    while (list)
	{
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

void	flood_fill(t_win game, t_pos start, t_pos target)
{
	if (mark_if_visited(game, (t_pos){start.x + 1, start.y}))
		flood_fill(game, (t_pos){start.x + 1, start.y}, target);
	if (mark_if_visited(game, (t_pos){start.x - 1, start.y}))
		flood_fill(game, (t_pos){start.x - 1, start.y}, target);
	if (mark_if_visited(game, (t_pos){start.x, start.y + 1}))
		flood_fill(game, (t_pos){start.x, start.y + 1}, target);
	if (mark_if_visited(game, (t_pos){start.x, start.y - 1}))
		flood_fill(game, (t_pos){start.x, start.y - 1}, target);
}

int mark_if_visited(t_win game, t_pos target)
{
	if (game.map_copy[target.y][target.x] == '0' || game.map_copy[target.y][target.x] == 'C' \
									|| game.map_copy[target.y][target.x] == 'E')
	{
		game.map_copy[target.y][target.x] = 'x';
		return (1);
	}
	return (0);
}

int check_if_visited(t_win game, t_pos target)
{
	if (game.file_map[target.y][target.x] == game.map_copy[target.y][target.x])
		return (1);
	return (0);
}

int	listed_flood_fill(t_win	game, t_pos_list *collectibles, t_pos target)
{
	t_pos_list *tmp;

	tmp = collectibles;
	while (tmp)
	{
		flood_fill(game, tmp->pos, target);
		tmp = tmp->next;
	}
	tmp = collectibles;
	while (tmp)
	{
		if (!check_if_visited(game, tmp->pos))
		{
			return (check_if_visited(game, tmp->pos));
		}
		tmp = tmp->next;
	}
	return (1);
}