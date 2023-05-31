/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:22:11 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/31 15:17:10 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

# include <unistd.h>
# include <stdlib.h>
# include<stdio.h>

void	set_buffer_zero(char *buffer);
char	*buffer_to_line_process(char *line, char *buffer);
int		line_lenght(char *line);
int		ft_buffer_shift(char *buffer);
#endif