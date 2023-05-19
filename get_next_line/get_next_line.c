/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:22:06 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/19 15:05:15 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
    static size_t buffer_pos;
	static	ssize_t	 buffer_size;

	line = NULL;
	buffer_size = ft_read_fd(fd);
	buffer_pos = 0;
}

int main()
{
	get_next_line("Hello");
	return(0);
}