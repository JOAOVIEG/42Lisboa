/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:22:11 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/29 18:52:57 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE	1

# include <unistd.h>
# include <stdlib.h>
# include<stdio.h>

char			*get_next_line(int fd);
static int		read_bytes(int fd, int bytes_read, char buffer[BUFFER_SIZE]);
static char		*buffer_c_process(int bytes_read, char *buffer, \
											int line_capacity);
static char		*ft_strcpy(char *new_line, char *buffer);
void			buffer_update(int bytes_read, int i, char *buffer);
#endif