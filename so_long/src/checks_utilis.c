/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utilis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:02:08 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/24 11:07:19 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	char_msg(int check_nbr_chrs, t_win *game)
{
	if (check_nbr_chrs == 1)
		game_error_msg("Error\nMap has no player\n", game);
	else if (check_nbr_chrs == 2)
		game_error_msg("Error\nMap has no exit\n", game);
	else if (check_nbr_chrs == 3)
		game_error_msg("Error\nMap has no collectibles\n", game);
}

int	check_nbr_chrs(char **map, int height, int width)
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
	int	i;
	int	j;
	int	exit;

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
	int	i;
	int	j;
	int	player;

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
	int	i;
	int	j;
	int	collectible;

	i = 0;
	collectible = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	return (collectible);
}
