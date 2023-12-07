/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:11:42 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/07 17:00:52 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex(t_pipe *content, char **envp)
{
	if (pipe(content->end) < 0)
	{
		ft_printf("Error: pipe failed\n");
		exit(EXIT_FAILURE);
	}
	check_path(content, envp);
	content->pid1 = fork();
	if (content->pid1 < 0)
	{
		ft_printf("Error: fork failed\n");
		exit(EXIT_FAILURE);
	}
	else if (content->pid1 == 0)
		child_process(content, envp);
	content->pid2 = fork();
	if (content->pid2 < 0)
	{
		ft_printf("Error: fork failed\n");
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
		dup2(content->end[WRITE_END], STDOUT_FILENO);
		close(content->end[READ_END]);
		dup2(content->infile, STDIN_FILENO);
		execve(content->valid_path, content->cmd1, envp);
	}
	else
	{
		ft_printf("Error: %s\n", strerror(errno));
		wait_and_close_childs(content);
		main_close(content);
		exit(0);
	}
}

void	child_process2(t_pipe *content, char **envp)
{
	content->valid_path = get_cmd(content->cmd_paths, *content->cmd2);
	if (content->valid_path)
	{
		dup2(content->end[READ_END], STDIN_FILENO);
		close(content->end[WRITE_END]);
		dup2(content->outfile, STDOUT_FILENO);
		execve(content->valid_path, content->cmd2, envp);
	}
	else
	{
		ft_printf("Error: %s\n", strerror(errno));
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
	close(content->infile);
	close(content->outfile);
}
