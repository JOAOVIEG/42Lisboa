/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:24:05 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/25 22:47:36 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_error_msg(char *message, t_win *game)
{
	ft_printf("%s", message);
	if (game)
		shut_game_down(game);
	exit(EXIT_FAILURE);
}

void	shut_game_down(t_win *game)
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
