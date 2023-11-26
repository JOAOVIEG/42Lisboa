/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:10:51 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/26 17:11:33 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	visit(t_win *game, t_pos start, t_pos target)
{
	game->file_map[start.y][start.x] = '0';
	game->file_map[target.y][target.x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

void	open_house(t_win *game)
{
	int	img_width;
	int	img_height;

	mlx_destroy_image(game->mlx, game->img->exit);
	game->img->exit = mlx_xpm_file_to_image(game->mlx, \
		"assets/open_home.xpm", &img_width, &img_height);
}
