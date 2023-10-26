/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:45:37 by joaocard          #+#    #+#             */
/*   Updated: 2023/10/26 14:56:22 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

#define SO_LONG_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../libs/minilibx-linux/mlx.h"
#include "../libs/libft/libft.h"
#include "../libs/get_next_line/get_next_line.h"
#include <limits.h>
#include "../libs/ft_printf/ft_printf.h"
#include <stdlib.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef	struct s_game
{
	t_map	*map;
}	t_game;

int		so_long(char *file);
void	file_map_build(char *file, t_game *game);
int		check_file_ext(char *file);
void    free_map(t_map *map);
void	map_read(int fd, t_game *game);
int		is_rectangular(char **map, int height, int witdth);

#endif