/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:22:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/23 23:07:15 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "get_next_line.h"

static ssize_t	*ft_read_fd(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static size_t	buffer_pos;
	static ssize_t	buffer_size;

	buffer_pos = 0;
	buffer_size = 0;
	if (buffer_pos >= buffer_size)
	{
		if (fd == STD_INPUT)
			buffer_size = read(0, buffer, sizeof(buffer));
		else
		{
			buffer_size = read(fd, buffer, sizeof(buffer));
		}
	}
	if (buffer_size <= 0)
		return (NULL);
	buffer_pos = 0;
	return (buffer_size);
}*/
