/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:11:42 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/09 14:17:36 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex(t_pipe *content, char **envp)
{
	if (pipe(content->end) < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	check_path(content, envp);
	content->pid1 = fork();
	if (content->pid1 < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (content->pid1 == 0)
		child_process(content, envp);
	content->pid2 = fork();
	if (content->pid2 < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (content->pid2 == 0)
		child_process2(content, envp);
	wait_and_close_childs(content);
	main_close(content);
}

void	child_process(t_pipe *content, char **envp)
{
	content->valid_path = get_cmd(content->cmd_paths, *content->cmd1);
	if (content->valid_path)
	{
		if (dup2(content->end[WRITE_END], STDOUT_FILENO) < 0)
			dup_error(content);
		close(content->end[READ_END]);
		if (dup2(content->infile, STDIN_FILENO) < 0)
			dup_error(content);
		close(content->infile);
		if (execve(content->valid_path, content->cmd1, envp) < 0)
		{
			perror("Error: execve failed");
			main_close(content);
			free_pipex(content);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("Error: command not found");
		main_close(content);
		free_pipex(content);
		exit(EXIT_FAILURE);
	}
}

void	child_process2(t_pipe *content, char **envp)
{
	content->valid_path = get_cmd(content->cmd_paths, *content->cmd2);
	if (content->valid_path)
	{
		if (dup2(content->end[READ_END], STDIN_FILENO) < 0)
			dup_error(content);
		close(content->end[WRITE_END]);
		if (dup2(content->outfile, STDOUT_FILENO) < 0)
			dup_error(content);
		close(content->outfile);
		if (execve(content->valid_path, content->cmd2, envp) < 0)
		{
			perror("Error: execve failed");
			main_close(content);
			free_pipex(content);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("Error: command not found");
		main_close(content);
		free_pipex(content);
		exit(EXIT_FAILURE);
	}
}

void	wait_and_close_childs(t_pipe *content)
{
	close(content->end[READ_END]);
	close(content->end[WRITE_END]);
	if (content->pid1)
		waitpid(content->pid1, NULL, 0);
	if (content->pid2)
		waitpid(content->pid2, NULL, 0);
}

void	main_close(t_pipe *content)
{
	close(content->end[WRITE_END]);
	close(content->end[READ_END]);
	close(content->infile);
	close(content->outfile);
	close(0);
	close(1);
	close(2);
}
