/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:15:12 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/13 22:28:55 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	read_map(int fd, t_win *game)
{
	char	*line;

	line = 0;
	game->file_map = (char **)malloc(sizeof(char *) * 1);
	if (!game->file_map)
		game_error_msg("Error\nMalloc\n", game);
	map_init(game, fd, line);
}

void	map_init(t_win *game, int fd, char *line)
{
	game->map.width = 0;
	game->map.height = 0;
	copy_lines(game, fd, line);
	game->map.width = ft_strlen(game->file_map[0]);
}

void	copy_lines(t_win *game, int fd, char *line)
{
	char	**split_nline;
	int		i;
	int		map_size;

	i = 0;
	map_size = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] == '\0')
			game_error_msg("Error\nEmpty line\n", NULL);
		split_nline = ft_split(line, '\n');
		if (split_nline[0] == NULL)
			break ;
		game->file_map[i] = ft_strdup(split_nline[0]);
		free_strdup(split_nline);
		free(line);
		game->map.height++;
		i++;
		if (game->map.height >= map_size)
			map_size = resize_map(game, map_size);
	}
	game->file_map[i] = NULL;
}

int	resize_map(t_win *game, int map_size)
{
	map_size *= 2;
	game->file_map = (char **)ft_realloc(game->file_map, sizeof(char *) \
							* game->map.height, sizeof(char *) * map_size);
	if (!game->file_map)
		game_error_msg("Error\nRealloc\n", game);
	return (map_size);
}

void	free_strdup(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
