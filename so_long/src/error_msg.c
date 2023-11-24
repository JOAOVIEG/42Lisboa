/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:24:05 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/24 16:17:14 by joaocard         ###   ########.fr       */
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
	i = 0;
	game->map.height = 0;
	game->map.width = 0;
	if (game->img)
		shut_game(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
		free(game->mlx);
	free(game);
}

void	shut_game(t_win *game)
{
	if (game->img)
	{
		if (game->img->collectible)
			mlx_destroy_image(game->mlx, game->img->collectible);
		if (game->img->wall)
			mlx_destroy_image(game->mlx, game->img->wall);
		if (game->img->player)
			mlx_destroy_image(game->mlx, game->img->player);
		if (game->img->tile)
			mlx_destroy_image(game->mlx, game->img->tile);
		if (game->img->exit)
			mlx_destroy_image(game->mlx, game->img->exit);
		free(game->img);	
	}
}
