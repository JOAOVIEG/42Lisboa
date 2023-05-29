/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:22:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/29 19:17:55 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_bytes(int fd, int bytes_read, char buffer[BUFFER_SIZE])
{
	if (bytes_read == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (bytes_read);
}

static char	*buffer_c_process(int bytes_read, char *buffer, int line_capacity)
{
	int		i;
	int		j;
	int		line_lenght;
	char	*new_line;

	i = 0;
	line_lenght = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			line_lenght += i;
			new_line = (char *) malloc((line_lenght + 2) * (sizeof(char)));
			if (!new_line)
				return (NULL);
			else
			{
				new_line = ft_strcpy(new_line, buffer[i]);
				line_capacity = line_lenght + 2;
			}
			buffer_update(bytes_read, i, buffer[i]);
			return (new_line);
		}
		i++;
	}
}

static char	*ft_strcpy(char *new_line, char *buffer)
{
	int	i;
	int	index;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (buffer[i])
		i++;
	while (j <= i)
	{
		new_line[k] = buffer[j];
		k++;
	}
	new_line[k] = 0;
	return (new_line);
}

void	buffer_update(int bytes_read, int i, char *buffer)
{
	int	j;

	j = 0;
	bytes_read -= (i + 1);
	while (j < bytes_read)
	{
		buffer[j] = buffer[i + j + 1];
	}
}
