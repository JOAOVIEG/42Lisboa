/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:22:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/28 11:29:58 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	set_buffer_zero(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		buffer[i++] = 0;
	}
}

char	*buffer_to_line_process(char *line, char *buffer)
{
	char	*new_line;
	int		line_len;
	int		i;
	int		j;

	line_len = (line_lenght(line) + line_lenght(buffer)) + 1;
	i = 0;
	j = -1;
	new_line = (char *)malloc(sizeof(char) * line_len);
	if (!new_line)
		return (NULL);
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while (buffer[++j])
	{
		new_line[i++] = buffer[j];
		if (buffer[j] == '\n')
			break ;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

int	line_lenght(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	return (i + (line[i] == '\n'));
}

int	ft_buffer_shift(char *buffer)
{
	int	i;
	int	j;
	int	newline;

	i = 0;
	j = 0;
	newline = 0;
	while (buffer[i])
	{
		if (newline)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			newline = 1;
		buffer[i++] = '\0';
	}
	return (newline);
}
