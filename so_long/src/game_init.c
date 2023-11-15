/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:49:47 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/14 16:32:16 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_init(t_win *game)
{
	game->mlx = mlx_init();
	game->img = mlx_new_image(game->mlx, game->map.width * 100, \
			game->map.height * 100);
	game->mlx_win = mlx_new_window(game->mlx, game->map.width * 100, \
			game->map.height * 100, "so_long");
	events_handler(game);
	mlx_loop(game->mlx);
}

void	events_handler(t_win *game)
{
	mlx_hook(game->mlx_win, CROSS, 0, close_window, game);
	mlx_hook(game->mlx_win, 2, 1L<<0, key_press, game);
}

int	key_press(int keycode, t_win *game)
{
	if (keycode == ESC || keycode == Q)
		close_window(game);
	// if (keycode == W)
	// 	move_up(game);
	// if (keycode == A)
	// 	move_left(game);
	// if (keycode == S)
	// 	move_down(game);
	// if (keycode == D)
	// 	move_right(game);
	return (0);
}
/*void	movements_events(t_win *game)
{
	mlx_hook(game->mlx_win, W, 0, move_up, game);
	mlx_hook(game->mlx_win, A, 0, move_left, game);
	mlx_hook(game->mlx_win, S, 0, move_down, game);
	mlx_hook(game->mlx_win, D, 0, move_right, game);

}*/

int	close_window(t_win *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
	return (0);
}