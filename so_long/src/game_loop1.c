/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:14:18 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/28 11:00:08 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_press(int keycode, t_win *game)
{
	if (keycode == ESC || keycode == Q)
		close_window(game);
	else
	{
		movement(game, keycode);
	}
	return (0);
}

void	movement(t_win *game, int keycode)
{
	t_pos	player;

	player = get_player_pos(game->file_map, game->map.height, \
												game->map.width);
	if (keycode == W)
		player_visit(game, (t_pos){player.x, player.y}, \
						(t_pos){player.x, player.y - 1});
	if (keycode == A)
	{
		get_left_player(game);
		player_visit(game, (t_pos){player.x, player.y}, \
						(t_pos){player.x - 1, player.y});
	}
	if (keycode == S)
		player_visit(game, (t_pos){player.x, player.y}, \
						(t_pos){player.x, player.y + 1});
	if (keycode == D)
	{
		get_right_player(game);
		player_visit(game, (t_pos){player.x, player.y}, \
						(t_pos){player.x + 1, player.y});
	}
}

void	get_left_player(t_win *game)
{
	int		img_width;
	int		img_height;

	mlx_destroy_image(game->mlx, game->img->player);
	game->img->player = mlx_xpm_file_to_image(game->mlx, \
		"assets/player_left.xpm", &img_width, &img_height);
}

void	get_right_player(t_win *game)
{
	int		img_width;
	int		img_height;

	mlx_destroy_image(game->mlx, game->img->player);
	game->img->player = mlx_xpm_file_to_image(game->mlx, \
		"assets/player_right.xpm", &img_width, &img_height);
}

void	player_visit(t_win *game, t_pos start, t_pos target)
{
	if (game->file_map[target.y][target.x] != '1')
	{
		if (game->file_map[target.y][target.x] == '0' \
				|| game->file_map[target.y][target.x] == 'C')
		{
			visit(game, start, target);
			draw_game(game);
		}
		if (count_collectibles(game->file_map, \
					game->map.height, game->map.width) == 0)
		{
			open_house(game);
			draw_game(game);
		}
		if (game->file_map[target.y][target.x] == 'E' && \
			count_collectibles(game->file_map, game->map.height, \
											game->map.width) == 0)
		{
			visit_exit(game, start, target);
			draw_game(game);
			close_window(game);
		}
	}
}
