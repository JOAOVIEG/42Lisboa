/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:45:37 by joaocard          #+#    #+#             */
/*   Updated: 2023/10/12 17:19:31 by joaocard         ###   ########.fr       */
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
	int		collectible;
	int		exit;
	int		player;
	t_pos	*pos;
}	t_map;
void    check_file(char *file);
void    map_checks(char *file);
//int		is_rectangle(t_map **map);

#endif