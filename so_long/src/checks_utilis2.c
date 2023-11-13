/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utilis2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:04:09 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/13 22:29:38 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

int	mark_if_visited(t_win game, t_pos target)
{
	if (game.map_copy[target.y][target.x] == '0' \
					|| game.map_copy[target.y][target.x] == 'C' \
					|| game.map_copy[target.y][target.x] == 'E')
	{
		game.map_copy[target.y][target.x] = 'x';
		return (1);
	}
	return (0);
}

int	check_if_visited(t_win game, t_pos e_target, t_pos_list *c_target)
{
	int	target_met;

	target_met = 0;
	if (game.file_map[e_target.y][e_target.x] \
				== game.map_copy[e_target.y][e_target.x])
		target_met += 1;
	while (c_target)
	{
		if (game.file_map[c_target->pos.y][c_target->pos.x] \
			== game.map_copy[c_target->pos.y][c_target->pos.x])
		{
			target_met += 1;
			break ;
		}
		c_target = c_target->next;
	}
	return (target_met);
}

void	free_map_copy(t_win *game, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(game->map_copy[i]);
		i++;
	}
	free(game->map_copy);
	game->map_copy = NULL;
}

void	free_collectibles(t_pos_list *collectibles)
{
	t_pos_list	*tmp;

	while (collectibles != NULL)
	{
		tmp = collectibles;
		collectibles = collectibles->next;
		free(tmp);
	}
}
