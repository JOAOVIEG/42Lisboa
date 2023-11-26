/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:24:05 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/26 17:26:37 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_error_msg(char *message, t_win *game)
{
	ft_printf("%s", message);
	if (game)
		free_game(game);
	exit(EXIT_FAILURE);
}

void	free_game(t_win *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free(game->file_map[i]);
		i++;
	}
	free(game->file_map);
	game->file_map = NULL;
	i = 0;
	game->map.height = 0;
	game->map.width = 0;
	free(game);
	exit(EXIT_SUCCESS);
}

void	exit_game(t_win *game)
{
	mlx_destroy_image(game->mlx, game->img->player);
	mlx_destroy_image(game->mlx, game->img->exit);
	mlx_destroy_image(game->mlx, game->img->tile);
	mlx_destroy_image(game->mlx, game->img->wall);
	mlx_destroy_image(game->mlx, game->img->collectible);
	game->img->player = NULL;
	game->img->exit = NULL;
	game->img->tile = NULL;
	game->img->wall = NULL;
	game->img->collectible = NULL;
	free(game->img);
	game->img = NULL;
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
}

int	close_window(t_win *game)
{
	exit_game(game);
	free_game(game);
	return (0);
}

void	visit_exit(t_win *game, t_pos start, t_pos target)
{
	game->file_map[start.y][start.x] = '0';
	game->file_map[target.y][target.x] = 'E';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}
