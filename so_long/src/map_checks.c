/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/04 18:02:30 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_checks(t_win *game)
{
	if (!is_rectangular(game->file_map, game->map.height, game->map.width))
		game_error_msg("Error\nMap is not rectangular\n", game);
}

int	is_rectangular(char **map, int height, int width)
{
    int i;

    i = 0;
    while (i < height)
    {
        if (ft_strlen(map[i]) != (size_t)width)
            return (0);
        i++;
    }
    return (1);
}

