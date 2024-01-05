/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utilis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:01:53 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/05 13:07:51 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	pipe_construct(t_pipe *content)
{
	int	i;
	int	cmd_i;

	cmd_i = 0;
	while (cmd_i < content->cmd_i - 1)
	{
		i = 0;
		if (pipe(content->end[cmd_i]) < 0)
		{
			perror("pipe ERROR ");
			while (i < content->cmd_i)
			{
				close(content->end[i][WRITE_END]);
				close(content->end[i][READ_END]);
				i++;
			}
			free_pipex(content);
			exit(EXIT_FAILURE);
		}
		cmd_i++;
	}
}

void	fork_error(t_pipe *content)
{
	int	i;

	i = 0;
	perror("fork error at child ");
	while (i < content->cmd_i)
	{
		close(content->end[i][READ_END]);
		close(content->end[i][WRITE_END]);
		i++;
	}
	free_pipex(content);
	exit(EXIT_FAILURE);
}

void	dup_error(t_pipe *content)
{
	int	i;

	i = 0;
	perror("dup error at child");
	while (i < content->cmd_i)
	{
		close(content->end[i][READ_END]);
		close(content->end[i][WRITE_END]);
		i++;
	}
	free_pipex(content);
	exit(EXIT_FAILURE);
}

void	input_redirect(t_pipe *content, int cmd_i, char **av)
{
	if (cmd_i != 0)
	{
		if (dup2(content->end[cmd_i - 1][READ_END], STDIN_FILENO) < 0)
			dup_error(content);
	}
	else if (cmd_i == 0)
	{
		if (ft_strcmp("here_doc", av[1]) == 0)
			here_doc(content, av);
		else
		{
			content->infile = open(av[1], O_RDONLY);
			if (content->infile < 0)
			{
				perror("infile ERROR ");
				free_pipex(content);
				exit(EXIT_FAILURE);
			}
		}
		if (dup2(content->infile, STDIN_FILENO) < 0)
			dup_error(content);
	}
}

void	output_redirect(t_pipe *content, int cmd_i, char **av, int ac)
{
	if (cmd_i != content->cmd_i - 1)
	{
		if (dup2(content->end[cmd_i][WRITE_END], STDOUT_FILENO) < 0)
			dup_error(content);
	}
	else if (cmd_i == content->cmd_i - 1)
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
