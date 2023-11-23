/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:49:47 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/23 17:56:29 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_init(t_win *game)
{
	game->mlx = mlx_init();
	game->img = mlx_new_image(game->mlx, game->map.width * 64, \
	 	game->map.height * 64);
	game->mlx_win = mlx_new_window(game->mlx, game->map.width * 64, \
		game->map.height * 64, "so_long");
 	load_images(game);
	draw_game(game);
	events_handler(game);
	mlx_loop(game->mlx);
}

void	load_images(t_win *game)
{
	int	img_width;
	int	img_height;
	
	game->img->collectible = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", &img_width, &img_height);
	if(game->img->collectible == NULL)
	{
		game_error_msg("Error\nLoading images\n", game);
	}
	game->img->player = mlx_xpm_file_to_image(game->mlx, "assets/player_right.xpm", &img_width, &img_height);
	if(game->img->player == NULL)
	{
		game_error_msg("Error\nLoading images\n", game);
	}
	game->img->tile = mlx_xpm_file_to_image(game->mlx, "assets/grass.xpm", &img_width, &img_height);
	if(game->img->tile == NULL)
	{
		game_error_msg("Error\nLoading images\n", game);
	}
	game->img->wall = mlx_xpm_file_to_image(game->mlx, "assets/tree.xpm", &img_width, &img_height);
	if(game->img->wall == NULL)
	{
		game_error_msg("Error\nLoading images\n", game);
	}
	game->img->exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &img_width, &img_height);
	if(game->img->exit == NULL)
	{
		game_error_msg("Error\nLoading images\n", game);
	}
}

void	draw_game(t_win *game)
{
	int tile_size;
	int x;
	int y;
	
	y = 0;
	tile_size = 64;
	if(game->img == NULL)
	{
		game_error_msg("Error\nLoading images\n", game);
	}
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->file_map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->img->collectible, x * tile_size, y * tile_size);
			}
			if(game->file_map[y][x] == 'P')
			{		
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->img->player, x * tile_size, y * tile_size);
			}
			if(game->file_map[y][x] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->img->wall, x * tile_size, y * tile_size);
			}
			if(game->file_map[y][x] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->img->tile, x * tile_size, y * tile_size);
			}
			if(game->file_map[y][x] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->img->exit, x * tile_size, y * tile_size);
			}
			x++;
		}
		y++;
	}
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
	// {
	// 	player_visit(game, (t_pos){game->map.player.x, game->map.player.y}, 
	// 		(t_pos){game->map.player.x, game->map.player.y - 1});
	// }
	// if (keycode == A)
	// {
	// 	player_visit(game, (t_pos){game->map.player.x, game->map.player.y}, 
	// 		(t_pos){game->map.player.x - 1, game->map.player.y});
	// }
	// if (keycode == S)
	// {
	// 	player_visit(game, (t_pos){game->map.player.x, game->map.player.y}, 
	// 		(t_pos){game->map.player.x, game->map.player.y + 1});
	// }
	// if (keycode == D)
	// {
	// 	player_visit(game, (t_pos){game->map.player.x, game->map.player.y}, 
	// 		(t_pos){game->map.player.x + 1, game->map.player.y});
	// }
	return (0);
}


/*void player_visit(t_win *game, t_pos start, t_pos target)
{
	if (game->file_map[target.y][target.x] != '1')
	{
		if (game->file_map[target.y][target.x] == '0' || game->file_map[target.y][target.x] == 'C')
    	{
        	game->file_map[start.y][start.x] = '0';
			game->file_map[target.y][target.x] = 'P';
			game->map.player.x = target.x;
			game->map.player.y = target.y;
    	}
		if (game->file_map[target.y][target.x] == 'E')
		{
			game->file_map[start.y][start.x] = '0';
			game->file_map[target.y][target.x] = 'E';
			game->map.player.x = target.x;
			game->map.player.y = target.y;
			if (check_if_visited(*game, game->map.exit, game->map.collectibles) == 2)
			{
				shut_game(game);
			}
		}
	}


	draw_game(game);
}*/

int	close_window(t_win *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
	return (0);
}