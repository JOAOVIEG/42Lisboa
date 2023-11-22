/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:49:47 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/22 15:46:02 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_init(t_win *game)
{
	game->mlx = mlx_init();
	game->img = mlx_new_image(game->mlx, game->map.width * 64,
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
	
	game->img->collectible = mlx_xpm_file_to_image(game->mlx, "Apple.xpm", &img_width, &img_height);
	if(game->img->collectible == NULL)
	{
		game_error_msg("Error\nLoading images\n", game);
	}
	game->img->player = mlx_xpm_file_to_image(game->mlx, "assets/babywarrior.xpm", &img_width, &img_height);
	if(game->img->player == NULL)
	{
		game_error_msg("Error\nLoading images\n", game);
	}
	game->img->tile = mlx_xpm_file_to_image(game->mlx, "assets/hills.xpm", &img_width, &img_height);
	if(game->img->tile == NULL)
	{
		game_error_msg("Error\nLoading images\n", game);
	}
	game->img->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &img_width, &img_height);
	if(game->img->wall == NULL)
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
	if(game->img->collectible == NULL)
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
					game->img->tile, x * tile_size, y * tile_size);
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->img->collectible, x * tile_size, y * tile_size);
			}
			if(game->file_map[y][x] == 'P')
			{

				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->img->tile, x * tile_size, y * tile_size);				
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->img->player, x * tile_size, y * tile_size);
			}
			if(game->file_map[y][x] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, 
					game->img->wall, x * tile_size, y * tile_size);
			}
			if(game->file_map[y][x] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, 
					game->img->tile, x * tile_size, y * tile_size);
			}
			// if(game->file_map[y][x] == 'E')
			// {
			// 	mlx_put_image_to_window(game->mlx, game->mlx_win, 
			// 		game->img->exit, x * tile_size, y * tile_size);
			// }
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