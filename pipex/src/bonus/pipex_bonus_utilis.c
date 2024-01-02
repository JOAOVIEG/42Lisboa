/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utilis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:01:53 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/02 15:11:59 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	pipe_construct(t_pipe *content)
{
	int 	i;
	int		nr_pipes;

	nr_pipes = 0;
	while (nr_pipes < content->pipe_index - 1)
	{
		i = 0;
		if (pipe(content->end[nr_pipes]) < 0)
		{
			perror("pipe ERROR ");
			while (i < content->pipe_index)
			{
				close(content->end[i][WRITE_END]);
				close(content->end[i][READ_END]);
				i++;
			}
			free_pipex(content);
			exit(EXIT_FAILURE);
		}
		nr_pipes++;
	}
}

void	fork_error(t_pipe *content)
{
	int	i;
	
	i = 0;
	perror("fork error at child ");
	while (i < content->pipe_index)
	{
		close(content->end[i][READ_END]);
		close(content->end[i][WRITE_END]);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	dup_error(t_pipe * content)
{
	int	i;
	
	i = 0;
	perror("dup error at child");
	while (i < content->pipe_index)
	{
		close(content->end[i][READ_END]);
		close(content->end[i][WRITE_END]);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	input_redirect(t_pipe *content, int nr_pipes, char **av)
{
	if (nr_pipes != 0)
	{
		if (dup2(content->end[nr_pipes - 1][READ_END], STDIN_FILENO) < 0)
			dup_error(content);
	}
	else if (nr_pipes == 0)
	{
		content->infile = open(av[1], O_RDONLY);
		if (content->infile < 0)
		{
			perror("infile ERROR ");
			free_pipex(content);
			exit(EXIT_FAILURE);
		}
		if (dup2(content->infile, STDIN_FILENO) < 0)
			dup_error(content);
	}
}

void	output_redirect(t_pipe *content, int nr_pipes, char **av, int ac)
{
	if (nr_pipes != content->pipe_index - 1)
	{
		if (dup2(content->end[nr_pipes][WRITE_END], STDOUT_FILENO) < 0)
			dup_error(content);
	}
	else if (nr_pipes == content->pipe_index - 1)
	{
		content->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (content->outfile < 0)
		{
			perror("outfile ERROR ");
			free_pipex(content);
			exit(EXIT_FAILURE);
		}
		if (dup2(content->outfile, STDOUT_FILENO) < 0)
			dup_error(content);
	}
}
