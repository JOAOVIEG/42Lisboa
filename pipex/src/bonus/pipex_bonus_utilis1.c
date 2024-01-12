/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utilis1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:12:28 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/12 09:44:14 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	close_child_pipes(t_pipe *content)
{
	int	i;

	i = 0;
	while (i < content->cmd_i)
	{
		if (content->end[i][READ_END] != -1)
		{
			close(content->end[i][READ_END]);
			content->end[i][READ_END] = -1;
		}
		if (content->end[i][WRITE_END] != -1)
		{
			close(content->end[i][WRITE_END]);
			content->end[i][WRITE_END] = -1;
		}
		i++;
	}
}

void	close_parent_pipes(t_pipe *content, int nr_pipes)
{
	if (nr_pipes != 0)
	{
		if (content->end[nr_pipes - 1][READ_END] != -1)
			close(content->end[nr_pipes - 1][READ_END]);
		content->end[nr_pipes - 1][READ_END] = -1;
	}
	if (content->end[nr_pipes][WRITE_END] != -1)
		close(content->end[nr_pipes][WRITE_END]);
	content->end[nr_pipes][WRITE_END] = -1;
	if (nr_pipes == 0)
	{
		if (content->infile != -1)
			close(content->infile);
		content->infile = -1;
	}
	if (nr_pipes == content->cmd_i - 1)
	{
		if (content->outfile != -1)
			close(content->outfile);
		content->outfile = -1;
	}
}

void	wait_childs(t_pipe *content)
{
	int	i;

	i = 0;
	while (i < content->cmd_i)
	{
		waitpid(content->pids[i], NULL, 0);
		i++;
	}
}

void	exec_fail(t_pipe *content)
{
	perror("Error: execve failed");
	if (content->infile != -1)
		close(content->infile);
	if (content->outfile != -1)
		close(content->outfile);
	close(0);
	close(1);
	free_pipex(content);
	exit(EXIT_FAILURE);
}

void	command_error(t_pipe *content)
{
	perror("Error getting command");
	close_child_pipes(content);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	free_pipex(content);
	exit(EXIT_FAILURE);
}
