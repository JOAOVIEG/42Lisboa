/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:24:05 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/04 13:52:03 by joaocard         ###   ########.fr       */
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
	/*while (i < game->map.height)
	{
		free(game->lines_n[i]);
		i++;
	}*/
	game->map.height = 0;
	game->map.width = 0;
	free(game);
	//exit(EXIT_SUCCESS);
	//shut_game(game);
}

/*void	shut_game(t_win *game)
{
	free(game->lines_n);
	free(game->img->wall);
	free(game->img->player);
	free(game->img->collectible);
	free(game->img->exit);
	free(game->img);
	free(game);
	exit(EXIT_SUCCESS);
}*/