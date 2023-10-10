/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:26:43 by joaocard          #+#    #+#             */
/*   Updated: 2023/06/02 11:26:06 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 0)
	{
		i = 0;
		if (fd >= 0 && fd <= FOPEN_MAX)
		{
			while (buffer[fd][i])
				buffer[fd][i++] = 0;
		}
		return (NULL);
	}
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = buffer_to_line_process(line, buffer[fd]);
		if (ft_buffer_shift(buffer[fd]))
			break ;
	}
	return (line);
}
