/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:45:37 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/26 17:12:36 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libs/libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../libs/get_next_line/get_next_line.h"
# include <limits.h>
# include "../libs/ft_printf/ft_printf.h"
# include <stdlib.h>

# define ESC 	65307
# define W 		119
# define A 		97
# define S 		115
# define D 		100
# define Q 		113
# define CROSS 	33

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_pos_list
{
	t_pos				pos;
	struct s_pos_list	*next;
}						t_pos_list;

typedef struct s_map
{
	int			width;
	int			height;
	t_pos		player;
	t_pos		exit;
	t_pos_list	*collectibles;
}			t_map;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*collectible;
	void	*tile;
	void	*exit;
}			t_img;

typedef struct s_win
{
	char	**file_map;
	char	**map_copy;
	void	*mlx;
	void	*mlx_win;
	int		moves;
	int		end;
	t_map	map;
	t_img	*img;
}			t_win;

void		so_long(char *file);
void		game_error_msg(char *message, t_win *game);
void		free_game(t_win *game);
void		exit_game(t_win *game);
void		game_build(char *file, t_win *game);
int			check_file_ext(char *file);
void		read_map(int fd, t_win *game);
void		map_init(t_win *game, int fd, char *line);
void		copy_lines(t_win *game, int fd, char *line);
int			resize_map(t_win *game, int map_size);
void		map_checks(t_win *game);
void		free_strdup(char **str);
int			is_rectangular(char **map, int height, int witdth);
int			is_closed(char **map, int height, int width);
int			is_valid_chars(char **map, int height, int width);
int			check_duplicate_char(char **map, int height, int width);
int			count_exit(char **map, int height, int width);
int			count_player(char **map, int height, int width);
int			count_collectibles(char **map, int height, int width);
int			check_nbr_chrs(char **map, int height, int width);
int			check_path_to_exit(t_win *game, int height, int width);
char		**copy_map(t_win *game);
t_pos		get_player_pos(char **map, int height, int width);
t_pos		get_exit_pos(char **map, int height, int width);
t_pos_list	*get_collectible_pos(char **map, int height, int width);
void		flood_fill(t_win map, t_pos start, t_pos target);
int			check_if_visited(t_win game, t_pos e_target, t_pos_list *c_target);
int			mark_if_visited(t_win game, t_pos target);
void		char_msg(int check_nbr_chrs, t_win *game);
void		free_collectibles(t_pos_list *collectibles);
void		free_map_copy(t_win *game, int height);
void		game_loop(t_win *game);
int			close_window(t_win *game);
void		start(t_win *game);
void		events_handler(t_win *game);
int			key_press(int keycode, t_win *game);
void		load_images(t_win *game);
void		draw_game(t_win *game);
void		movement(t_win *game, int keycode);
void		player_visit(t_win *game, t_pos start, t_pos target);
void		get_image(t_win *game, int x, int y);
void		visit(t_win *game, t_pos start, t_pos target);
void		open_house(t_win *game);
void		visit_exit(t_win *game, t_pos start, t_pos target);
void		get_left_player(t_win *game);
void		get_right_player(t_win *game);
#endif