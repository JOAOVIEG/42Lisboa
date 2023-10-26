/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:15:12 by joaocard          #+#    #+#             */
/*   Updated: 2023/10/26 15:10:12 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    free_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->height)
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
    free(map);
}

int  is_rectangular(char **map, int height, int width)
{
    int i;

    i = 1;
    while (i < height)
    {
        if (ft_strlen(map[i]) != (size_t)width)
            return (0);
        i++;
    }
    return (1);
}

void	map_read(int fd, t_game *game)
{
	char	*line;
	int 	ret;
	int		i;

	game->map = (t_map *)malloc(sizeof(t_map));
	if (!game->map)
	{
		ft_printf("Error\nFailed to allocate memory for map\n");
		exit(EXIT_FAILURE);
	}
	game->map->height = 0;
	i = 0;
	ret = -1;
	line = get_next_line(fd);
    if (!line)
    {
        ft_printf("Error\nFailed to read map file AQUI\n");
        exit(EXIT_FAILURE);
    }
    game->map->width = ft_strlen(line);
    game->map->height++;
    game->map->map = (char **)malloc(sizeof(char *) * game->map->height);
    if (!game->map->map)
    {
        ft_printf("Error\nFailed to allocate memory for map\n");
        exit(EXIT_FAILURE);
    }
    game->map->map[i] = ft_strdup(line);
    i++;
    free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i == 0)
			game->map->width = ft_strlen(line);
		game->map->height++;
		game->map->map = (char **)malloc(sizeof(char *) * game->map->height);
		if (!game->map->map)
		{
			ft_printf("Error\nFailed to allocate memory for map\n");
			free_map(game->map);
			exit(EXIT_FAILURE);
		}
		game->map->map[i] = ft_strdup(line);
		i++;
		free(line);
		ret = 1;
	}
	if (ret == -1)
	{
		ft_printf("Error\nFailed to read map file\n");
		exit(EXIT_FAILURE);
	}
	game->map->height++;
	    game->map->map = (char **)malloc(sizeof(char *) * game->map->height);
    if (!game->map->map)
    {
        ft_printf("Error\nFailed to allocate memory for map\n");
        exit(EXIT_FAILURE);
    }
    game->map->map[i] = ft_strdup(line);
    game->map->map[game->map->height - 1] = NULL;
    free(line);
    if (!is_rectangular(game->map->map, game->map->height, game->map->width))
    {
        ft_printf("Error\nMap is not rectangular\n");
        exit(EXIT_FAILURE);
    }
}