/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utilis1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:02:24 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/13 22:28:19 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_path_to_exit(t_win *game, int height, int width)
{
	t_pos_list	*collectibles;
	t_pos		player;
	t_pos		exit;
	int			result;

	game->map_copy = copy_map(game);
	player = get_player_pos(game->map_copy, height, width);
	exit = get_exit_pos(game->map_copy, height, width);
	collectibles = get_collectible_pos(game->map_copy, height, width);
	flood_fill(*game, player, exit);
	result = check_if_visited(*game, exit, collectibles);
	free_map_copy(game, height);
	free_collectibles(collectibles);
	return (result);
}

char	**copy_map(t_win *game)
{
	int	i;

	i = 0;
	game->map_copy = (char **)malloc(sizeof(char *) * game->map.height);
	if (!game->map_copy)
		game_error_msg("Error\nMalloc\n", game);
	while (i < game->map.height)
	{
		game->map_copy[i] = ft_strdup(game->file_map[i]);
		if (!game->map_copy)
			game_error_msg("Error\nMalloc\n", game);
		i++;
	}
	return (game->map_copy);
}

t_pos	get_player_pos(char **map, int height, int width)
{
	int		i;
	int		j;
	t_pos	pos;

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
	int		i;
	int		j;
	t_pos	pos;

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
	int			i;
	int			j;
	t_pos_list	*collectibles;
	t_pos_list	*tmp;

	i = 0;
	collectibles = NULL;
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
