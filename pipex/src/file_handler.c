/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:12:43 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/09 16:03:56 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_init_pipe(t_pipe **pipe, char **av)
{
	t_pipe	*content;

	content = malloc(sizeof(t_pipe));
	if (!content)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	content->paths = NULL;
	content->cmd_paths = NULL;
	content->valid_path = NULL;
	content->cmd1 = ft_split(av[2], ' ');
	content->cmd2 = ft_split(av[3], ' ');
	content->infile = -1;
	content->outfile = -1;
	*pipe = content;
}

void	free_pipex(t_pipe *pipe)
{
	int	i;

	i = 0;
	if (pipe->paths)
		pipe->paths = NULL;
	if (pipe->cmd_paths)
	{
		while (pipe->cmd_paths[i])
		{
			free(pipe->cmd_paths[i]);
			i++;
		}
		free(pipe->cmd_paths);
	}
	if (pipe->valid_path)
		free(pipe->valid_path);
	if (pipe->cmd1)
		free_cmd1(pipe);
	if (pipe->cmd2)
		free_cmd2(pipe);
	free(pipe);
}

void	free_cmd1(t_pipe *pipe)
{
	int	i;

	i = 0;
	while (pipe->cmd1[i])
	{
		free(pipe->cmd1[i]);
		i++;
	}
	free(pipe->cmd1);
}

void	open_error(t_pipe *content)
{
	perror("Error opening file");
	close(content->end[READ_END]);
	close(content->end[WRITE_END]);
	free_pipex(content);
	exit(EXIT_FAILURE);
}

void	command_error(t_pipe *content)
{
	perror("Error: command not found");
	main_close(content);
	free_pipex(content);
	exit(EXIT_FAILURE);
}
