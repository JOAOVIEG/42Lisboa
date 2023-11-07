/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:24:05 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/07 11:55:25 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void game_error_msg(char *message, t_win *game)
{
    ft_printf("%s", message);
    if (game)
        shut_game_down(game);
    exit(EXIT_FAILURE);
}

void    shut_game_down(t_win *game)
{
	int i;
	
	i = 0;
	while (i < game->map.height)
	{
		free(game->file_map[i]);
		i++;
	}
	free(game->file_map);
	i = 0;
	if(game->map_copy)
	{
		while (i < game->map.height)
		{
			free(game->map_copy[i]);
			i++;
		}
	}
	game->map.height = 0;
	game->map.width = 0;
	shut_game(game);
}

void	shut_game(t_win *game)
{
	free(game->map_copy);
	/*free(game->img->wall);
	free(game->img->player);
	free(game->img->collectible);
	free(game->img->exit);
	free(game->img);*/
	free(game);
	exit(EXIT_SUCCESS);
}