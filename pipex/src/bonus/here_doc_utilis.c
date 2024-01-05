/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:41:17 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/05 13:13:20 by joaocard         ###   ########.fr       */
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
		free_pipex(content);
		exit(EXIT_FAILURE);
	}
	buffer = read_from_stdin(av, buffer, buffer_size);
	if (buffer == NULL)
		stdin_error(content);
	write(here_doc_fd, buffer, ft_strlen(buffer));
	close(here_doc_fd);
	content->infile = open("in.txt", O_RDONLY);
	unlink("in.txt");
	if (content->infile < 0)
		infile_error(content);
	free(buffer);
}

char	*read_from_stdin(char **av, char *buffer, size_t buffer_size)
{
	char	ch;
	char	*delimiter_line;

	delimiter_line = ft_strjoin(av[2], "\n");
	while (read(STDIN_FILENO, &ch, 1) > 0)
	{
		buffer = ft_realloc(buffer, buffer_size + 2);
		buffer[buffer_size++] = ch;
		buffer[buffer_size] = '\0';
		if (ft_strnstr(buffer, delimiter_line, buffer_size) == \
						buffer + buffer_size - ft_strlen(delimiter_line))
		{
			buffer_size -= ft_strlen(delimiter_line);
			buffer[buffer_size] = '\0';
			break ;
		}
	}
	free(delimiter_line);
	return (buffer);
}

void	stdin_error(t_pipe *content)
{
	perror("Read from STIN ERROR");
	free_pipex(content);
	exit(EXIT_FAILURE);
}

void	infile_error(t_pipe *content)
{
	perror("infile ERROR ");
	free_pipex(content);
	exit(EXIT_FAILURE);
}
