/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:11:42 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/09 16:06:01 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex(t_pipe *content, char **envp, char **av, int ac)
{
	if (pipe(content->end) < 0)
	{
		perror("Error");
		free_pipex(content);
		exit(EXIT_FAILURE);
	}
	check_path(content, envp);
	content->pid1 = fork();
	if (content->pid1 < 0)
	{
		perror("Error");
		free_pipex(content);
		exit(EXIT_FAILURE);
	}
	else if (content->pid1 == 0)
		child_process(content, envp, av);
	content->pid2 = fork();
	if (content->pid2 < 0)
	{
		perror("Error");
		free_pipex(content);
		exit(EXIT_FAILURE);
	}
	else if (content->pid2 == 0)
		child_process2(content, envp, av, ac);
}

void	child_process(t_pipe *content, char **envp, char **av)
{
	content->infile = open(av[1], O_RDONLY);
	if (content->infile < 0)
		open_error(content);
	content->valid_path = get_cmd(content->cmd_paths, *content->cmd1);
	if (content->valid_path)
	{
		if (dup2(content->end[WRITE_END], STDOUT_FILENO) < 0)
			dup_error(content);
		close(content->end[READ_END]);
		close(content->end[WRITE_END]);
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
		command_error(content);
}

void	child_process2(t_pipe *content, char **envp, char **av, int ac)
{
	content->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (content->outfile < 0)
		open_error(content);
	content->valid_path = get_cmd(content->cmd_paths, *content->cmd2);
	if (content->valid_path)
	{
		if (dup2(content->end[READ_END], STDIN_FILENO) < 0)
			dup_error(content);
		close(content->end[WRITE_END]);
		close(content->end[READ_END]);
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
		command_error(content);
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
	if (content->infile != -1)
		close(content->infile);
	if (content->outfile != -1)
		close(content->outfile);
}
