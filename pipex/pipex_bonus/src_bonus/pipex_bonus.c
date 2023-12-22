/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:20:13 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/22 17:28:12 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

void	pipex(t_pipe *content, char **envp, int ac)
{
	int		fd_index;
	int 	i;
	
	i = 0;
	fd_index = 0;
	/*This block creates pipes for each*/
	/*cmd*/
	while (fd_index < content->pipe_index)
	{
		if (pipe(content->end[fd_index]) < 0)
		{
			perror("pipe ERROR ");
			main_close(content);
			free_pipex(content);
			exit(EXIT_FAILURE);
		}
		check_path(content, envp);
		fd_index++;
	}
	fd_index = 0;
	while (fd_index < content->pipe_index)
	{
		content->pids[fd_index] = fork();
		if (content->pids[fd_index] < 0)
		{
			perror("fork error at child ");
			exit(EXIT_FAILURE);
		}
		else if (fd_index == 0 && content->pids[fd_index] == 0)
		{
			if(child_1(content, envp, fd_index) < 0)
			{
				perror("ERROR at child 1 ");
				exit(EXIT_FAILURE);
			}
		}
		else if ((fd_index == (content->pipe_index - 1)) && content->pids[fd_index] == 0)
		{
			if (child_n(content, envp, fd_index) < 0)
			{
				perror("ERROR at child n ");
				exit(EXIT_FAILURE);
			}
		}
		else if ((fd_index != 0 && (fd_index != content->pipe_index - 1)) && content->pids[fd_index] == 0)
		{
			if (middle_child(content, envp, fd_index) < 0)
			{
				perror("ERROR at child n ");
				exit(EXIT_FAILURE);
			}
		}
		while (i < content->pipe_index)
		{
			close(content->end[i][READ_END]);
			close(content->end[i][WRITE_END]);
		}
		fd_index++;
	}
}

pid_t	child_1(t_pipe *content, char **envp, int fd_index)
{
	int i;
	i = 0;
	content->valid_path = get_cmd(content->cmd_paths, *content->cmd[fd_index]);
	if (content->valid_path)
	{
		if (dup2(content->end[fd_index][WRITE_END], STDOUT_FILENO) < 0)
			dup_error(content);
		if (dup2(content->infile, STDIN_FILENO) < 0)
			dup_error(content);
		close(content->infile);
		while (i < content->pipe_index)
		{
			if (i != fd_index)
				close(content->end[i][WRITE_END]);
			close(content->end[i][READ_END]);
			i++;
		}
		if (execve(content->valid_path, content->cmd[fd_index], envp) < 0)
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
	return(content->pids[fd_index]);
}
pid_t	middle_child(t_pipe *content, char **envp, int fd_index)
{
	int i;
	i = 0;
	content->valid_path = get_cmd(content->cmd_paths, *content->cmd[fd_index]);
	if (content->valid_path)
	{
		if (dup2(content->end[fd_index - 1][READ_END], STDIN_FILENO) < 0)
			dup_error(content);
		if (dup2(content->end[fd_index][WRITE_END], STDOUT_FILENO) < 0)
			dup_error(content);
		while (i < content->pipe_index)
		{
			if (i != fd_index - 1)
				close(content->end[i][READ_END]);
			if (i != fd_index)
				close(content->end[i][WRITE_END]);
			i++;
		}
		if (execve(content->valid_path, content->cmd[fd_index], envp) < 0)
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
	return (content->pids[fd_index]);
}

pid_t	child_n(t_pipe *content, char **envp, int fd_index)
{
	int i;

	i = 0;
	content->valid_path = get_cmd(content->cmd_paths, *content->cmd[fd_index]);
	if (content->valid_path)
	{
		if (dup2(content->end[(fd_index - 1)][READ_END], STDIN_FILENO) < 0)
			dup_error(content);
		if (dup2(content->outfile, STDOUT_FILENO) < 0)
			dup_error(content);
		close(content->outfile);
		while (i < content->pipe_index)
		{
			if (i != fd_index - 1)
				close(content->end[i][READ_END]);
			close(content->end[i][WRITE_END]);
		}
		if (execve(content->valid_path, content->cmd[fd_index], envp) < 0)
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
	return (content->pids[fd_index]);
}

// void	wait_and_close_childs(t_pipe *content)
// {
// 	close(content->end[READ_END]);
// 	close(content->end[WRITE_END]);
// 	if (content->pid1)
// 		waitpid(content->pid1, NULL, 0);
// 	if (content->pid2)
// 		waitpid(content->pid2, NULL, 0);
// }

// void	main_close(t_pipe *content)
// {
// 	close(content->end[WRITE_END]);
// 	close(content->end[READ_END]);
// 	close(content->infile);
// 	close(content->outfile);
// }
