/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:45:37 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/04 18:08:39 by joaocard         ###   ########.fr       */
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
#include <X11/X.h>
#include <X11/keysym.h>
#include "../libs/libft/libft.h"
#include "../libs/get_next_line/get_next_line.h"
#include <limits.h>
#include "../libs/ft_printf/ft_printf.h"
#include <stdlib.h>

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_map
{
	int		width;
	int		height;
	//int		player;
	//int 	exit;
	//int 	collectible;
	//t_pos	pos;
}			t_map;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}			t_img;

typedef	struct s_win
{
	char	**file_map;
	//char	**lines_n;
	//void	*mlx_ptr;
	//void	*win_ptr;
	//int		n_moves;
	t_map	map;
	//t_img	*img;
}			t_win;

void	so_long(char *file);
void	game_error_msg(char *message, t_win *game);
void    shut_game_down(t_win *game);
void	shut_game(t_win *game);
void	game_build(char *file, t_win *game);
int		check_file_ext(char *file);
void	read_map(int fd, t_win *game);
void	map_init(t_win *game, int fd, char *line);
void	copy_lines(t_win *game, int fd, char *line);
int		resize_map(t_win *game, int map_size);
void	map_checks(t_win *game);
void	free_strdup(char **str);
int		is_rectangular(char **map, int height, int witdth);

#endif