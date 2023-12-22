/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:55:53 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/22 17:46:37 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

void	ft_init_xpipe(t_pipe **pipe, char **av, int ac)
{
	t_pipe	*content;
	int		fd_index;
	int		i;

	content = malloc(sizeof(t_pipe));
	if (!content)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	content->pipe_index = ac - 2;
	fd_index = 0;
	i = 2;
	content->paths = NULL;
	content->cmd_paths = NULL;
	content->valid_path = NULL;
	content->pids = malloc(sizeof(pid_t) * content->pipe_index);
	content->end = malloc(sizeof(int*) * content->pipe_index);
	content->end[content->pipe_index] = malloc(sizeof(int) * 2);
	if (!content->end)
	{
		perror("end malloc ERROR ");
		exit(EXIT_FAILURE);		
	}
	if (!content->end[content->pipe_index][2])
	{
		perror("end 2nd malloc ERROR ");
		exit(EXIT_FAILURE);
	}
	content->cmd = (char **)malloc(sizeof(char *) * content->pipe_index);
	if(!content->cmd)
	{
		perror("cmd malloc ERROR ");
		exit(EXIT_FAILURE);		
	}
	while (fd_index < content->pipe_index)
	{
		content->cmd[fd_index] = *ft_split(av[i], ' ');
		fd_index++;
		i++;
	}
	content->infile = -1;
	content->outfile = -1;
	*pipe = content;
}

void	main_init(int ac, char **av, t_pipe *pipe)
{
	int	infile;
	int	outfile;

	infile = open(av[1], O_RDONLY);
	if (infile < 0)
	{
		perror("Error ");
		free_pipex(pipe);
		exit(EXIT_FAILURE);
	}
	else
		pipe->infile = infile;
	outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("Error ");
		free_pipex(pipe);
		exit(EXIT_FAILURE);
	}
	else
		pipe->outfile = outfile;
	check_files(pipe->infile, pipe->outfile, pipe);
}

void	check_files(int infile, int outfile, t_pipe *pipe)
{
	if (infile < 0)
	{
		perror("Error");
		free_pipex(pipe);
		exit(EXIT_FAILURE);
	}
	if (outfile < 0)
	{
		perror("Error");
		free_pipex(pipe);
		exit(EXIT_FAILURE);
	}
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
	if (pipe->cmd)
		free_cmd(pipe);
	free(pipe);
}

void	free_cmd(t_pipe *pipe)
{
	int	i;

	i = 0;
	while (pipe->cmd[i])
	{
		free(pipe->cmd[i]);
		i++;
	}
	free(pipe->cmd);
}
