/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:49:47 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/25 23:10:52 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_init(t_win *game)
{
	game->mlx = mlx_init();
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
    
	game->img = malloc(sizeof(t_img));
    game->img->collectible = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", &img_width, &img_height);
    game->img->player = mlx_xpm_file_to_image(game->mlx, "assets/player_right.xpm", &img_width, &img_height);
    game->img->tile = mlx_xpm_file_to_image(game->mlx, "assets/grass.xpm", &img_width, &img_height);
    game->img->wall = mlx_xpm_file_to_image(game->mlx, "assets/tree.xpm", &img_width, &img_height);
    game->img->exit = mlx_xpm_file_to_image(game->mlx, "assets/closed_home.xpm", &img_width, &img_height);
}

void	draw_game(t_win *game)
{
	int x;
	int y;
	
	y = 0;
	if(game->img == NULL)
	{
		game_error_msg("Error\nLoading images\n", game);
	}
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			get_image(game, x, y);
			x++;
		}
		y++;
	}
}

void get_image(t_win *game, int x, int y)
{
	if (game->file_map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img->collectible, x * 64, y * 64);
	}
	if(game->file_map[y][x] == 'P')
	{		
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img->player, x * 64, y * 64);
	}
	if(game->file_map[y][x] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img->wall, x * 64, y * 64);
	}
	if(game->file_map[y][x] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img->tile, x * 64, y * 64);
	}
	if(game->file_map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img->exit, x * 64, y * 64);
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
	else
	{
		movement(game, keycode);
	}
	return (0);
}

void	movement(t_win *game, int keycode)
{
    t_pos player;
    int img_width;
    int img_height;

    player = get_player_pos(game->file_map , game->map.height, game->map.width);
    if (keycode == W)
    {
        player_visit(game, (t_pos){player.x, player.y}, \
            (t_pos){player.x, player.y - 1});
    }
	if (keycode == A)
	{
		mlx_destroy_image(game->mlx, game->img->player);
   		game->img->player = mlx_xpm_file_to_image(game->mlx, "assets/player_left.xpm", &img_width, &img_height);
    	player_visit(game, (t_pos){player.x, player.y}, (t_pos){player.x - 1, player.y});
	}
    if (keycode == S)
    {
        player_visit(game, (t_pos){player.x, player.y}, \
            (t_pos){player.x, player.y + 1});
    }
    if (keycode == D)
	{
		mlx_destroy_image(game->mlx, game->img->player);
    	game->img->player = mlx_xpm_file_to_image(game->mlx, "assets/player_right.xpm", &img_width, &img_height);
    	player_visit(game, (t_pos){player.x, player.y}, (t_pos){player.x + 1, player.y});
	}
}

void player_visit(t_win *game, t_pos start, t_pos target)
{
	int img_width;
	int img_height;
	
	if (game->file_map[target.y][target.x] != '1')
	{
		if (game->file_map[target.y][target.x] == '0' || game->file_map[target.y][target.x] == 'C')
		{
			game->file_map[start.y][start.x] = '0';
			game->file_map[target.y][target.x] = 'P';
			game->moves++;
			ft_printf("Moves: %d\n", game->moves);
			draw_game(game);
		}
		if (count_collectibles(game->file_map, game->map.height, game->map.width) == 0)
		{
			mlx_destroy_image(game->mlx, game->img->exit);
    		game->img->exit = mlx_xpm_file_to_image(game->mlx, "assets/open_home.xpm", &img_width, &img_height);
		}
		if (game->file_map[target.y][target.x] == 'E' && count_collectibles(game->file_map, game->map.height, game->map.width) == 0)
		{
			game->file_map[start.y][start.x] = '0';
			game->file_map[target.y][target.x] = 'E';
			draw_game(game);
			game->moves++;
			ft_printf("Moves: %d\n", game->moves);
			close_window(game);
		}
	}
}

int	close_window(t_win *game)
{
	exit_game(game);
	shut_game_down(game);
	return (0);
}