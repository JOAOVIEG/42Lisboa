/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:22:11 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/30 01:43:02 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE	1

# include <unistd.h>
# include <stdlib.h>
# include<stdio.h>

char	*get_next_line(int fd);
char	*read_line(int fd, char *buffer, int *bytes_read, int *eof);
char	*buffer_process(char *buffer, int bytes_read, int *line_lenght, \
														int *line_capacity);
char	*resize_line_buffer(char *line, int line_lenght, int bytes_read, \
													int *line_capacity);

#endif