/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:11:42 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/06 23:12:35 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex(char **av, t_pipe *content, char **envp)
{
	if (pipe(content->end) < 0)
	{
		ft_printf("Error: pipe failed\n");
		exit(EXIT_FAILURE);
	}
	content->paths = get_path(envp);
	content->cmd_paths = ft_split(content->paths, ':');
	content->pid1 = fork();
	if (content->pid1 < 0)
	{
		ft_printf("Error: fork failed\n");
		exit(EXIT_FAILURE);
	}
	else if (content->pid1 == 0)
		child_process(av, content, envp);
	content->pid2 = fork();
	if (content->pid2 < 0)
	{
		ft_printf("Error: fork failed\n");
		exit(EXIT_FAILURE);
	}
	else if (content->pid2 == 0)
		child_process2(av, content, envp);
	wait_and_close_childs(content);
	main_close(content);
}

void	child_process(char **av, t_pipe *content, char **envp)
{
		dup2(content->end[WRITE_END], STDOUT_FILENO);
		close(content->end[READ_END]);
		dup2(content->infile, STDIN_FILENO);
		content->cmd_args = ft_split(av[2], ' ');
		content->cmd = get_cmd(content->cmd_paths, content->cmd_args[0]);
		execve(content->cmd, content->cmd_args, envp);
}

void	child_process2(char **av, t_pipe *content, char **envp)
{
	dup2(content->end[READ_END], STDIN_FILENO);
	close(content->end[WRITE_END]);
	dup2(content->outfile, STDOUT_FILENO);
	content->cmd_args = ft_split(av[3], ' ');
	content->cmd = get_cmd(content->cmd_paths, content->cmd_args[0]);
	execve(content->cmd, content->cmd_args, envp);
}

void	wait_and_close_childs(t_pipe *content)
{
	close(content->end[READ_END]);
	close(content->end[WRITE_END]);
	waitpid(content->pid1, NULL, 0);
	waitpid(content->pid2, NULL, 0);
}

void	main_close(t_pipe *content)
{
	close(content->infile);
	close(content->outfile);
}