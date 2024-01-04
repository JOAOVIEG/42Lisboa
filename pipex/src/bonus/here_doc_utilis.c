/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:41:17 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/04 13:49:33 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"


void	here_doc(t_pipe	*content, char **av)
{
	char	*buffer;
	size_t	buffer_size;
	int		here_doc_fd;

	buffer = NULL;
	buffer_size = 0;
	here_doc_fd = open("in.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (here_doc_fd < 0)
	{
		perror("Error opening here_doc file");
		exit(EXIT_FAILURE);
	}
	buffer = read_from_STDIN(av, buffer, buffer_size);
	write(here_doc_fd, buffer, ft_strlen(buffer));  // Write the entire buffer at once
	close(here_doc_fd);
	content->infile = open("in.txt", O_RDONLY);
	unlink("in.txt");
	if (content->infile < 0)
	{
		perror("infile ERROR ");
		free_pipex(content);
		exit(EXIT_FAILURE);
	}
	free(buffer);  // Free the buffer after use
}

char	*read_from_STDIN(char **av, char *buffer, size_t buffer_size)
{
	char	ch;
	char *delimiter_line;

	delimiter_line = NULL;
	while (read(STDIN_FILENO, &ch, 1) > 0)
	{
		// Temporarily add the character to the buffer
		buffer = realloc(buffer, buffer_size + 2);
		buffer[buffer_size++] = ch;
		buffer[buffer_size] = '\0';  // Null-terminate the buffer after each character

		// Check if the buffer ends with the delimiter followed by a newline
		delimiter_line = ft_strjoin(av[2], "\n");
		if (ft_strnstr(buffer, delimiter_line, buffer_size) == buffer + buffer_size - ft_strlen(delimiter_line))
		{
			// If the buffer ends with the delimiter followed by a newline, remove it from the buffer
			buffer_size -= ft_strlen(delimiter_line);  // Remove the delimiter and the newline from the buffer
			buffer[buffer_size] = '\0';  // Null-terminate the buffer after removing the delimiter
			break;
		}
		free(delimiter_line);
	}
	return (buffer);
}
