/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:22:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/30 01:59:14 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer, int *bytes_read, int *eof)
{
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read == 0)
	{
		*eof = 1;
		return (NULL);
	}
	if (*bytes_read < 0)
		return (NULL);
	return (buffer);
}

char	*buffer_process(char *buffer, int bytes_read, int *line_lenght, \
														int *line_capacity)
{
	char	*line;
	int		i;
	int		j;
	int		k;
	int		line_len;
	int		remaining_bytes;
	int		s;
	char	*new_line;

	line = NULL;
	i = 0;
	j = 0;
	k = 0;
	s = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			line_len = *line_lenght + i;
			new_line = (char *)malloc((line_len + 2) * sizeof(char));
			if (new_line != NULL)
			{
				while (j < i)
				{
					new_line[k] = buffer[j];
					k++;
					j++;
				}
				new_line[k] = '\0';
				line = new_line;
				*line_capacity = line_len + 2;
			}
			remaining_bytes = bytes_read - (i + 1);
			while (s < remaining_bytes)
			{
				buffer[s] = buffer[i + s + 1];
				s++;
			}
			*line_lenght = remaining_bytes;
			return (line);
		}
		i++;
	}
	return (NULL);
}

char	*resize_line_buffer(char *line, int line_lenght, int bytes_read, \
													int *line_capacity)
{
	int		new_capacity;
	int		j;
	char	*new_line;

	j = 0;
	if (line_lenght + bytes_read + 1 > *line_capacity)
	{
		new_capacity = line_lenght + bytes_read + 1;
		new_line = (char *)malloc(new_capacity * sizeof(char));
		if (new_line != NULL)
		{
			while (j < line_lenght)
			{
				new_line[j] = line[j];
			}
			free(line);
			line = new_line;
			*line_capacity = new_capacity;
		}
		else
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}
