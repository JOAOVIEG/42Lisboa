/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:20:13 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/01 15:58:33 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	pipex(t_pipe *content, char **envp, char **av, int ac)
{
    int		fd_index;
    int 	i;
    
    i = 0;
    fd_index = 0;
    check_path(content, envp);
    while (fd_index < content->pipe_index - 1)
    {
        if (pipe(content->end[fd_index]) < 0)
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
        fd_index++;
    }
    fd_index = 0;
    while (fd_index < content->pipe_index)
    {
        content->pids[fd_index] = fork();
        if (content->pids[fd_index] < 0)
        {
            perror("fork error at child ");
            while (i < content->pipe_index)
            {
                close(content->end[i][READ_END]);
                close(content->end[i][WRITE_END]);
                i++;
            }
            exit(EXIT_FAILURE);
        }
        else if (content->pids[fd_index] == 0)
        {
            // Child process
            if (fd_index != 0)
            {
                dup2(content->end[fd_index - 1][READ_END], STDIN_FILENO);
            }
            else if (fd_index == 0)
            {
                content->infile = open(av[1], O_RDONLY);
                if (content->infile < 0)
                {
                    perror("infile ERROR ");
                    free_pipex(content);
                    exit(EXIT_FAILURE);
                }
                dup2(content->infile, STDIN_FILENO);
            }
            if (fd_index != content->pipe_index - 1)
            {
                dup2(content->end[fd_index][WRITE_END], STDOUT_FILENO);
            }
            else if (fd_index == content->pipe_index - 1)
            {
                content->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (content->outfile < 0)
                {
                    perror("outfile ERROR ");
                    free_pipex(content);
                    exit(EXIT_FAILURE);
                }
                dup2(content->outfile, STDOUT_FILENO);
            }
			// Close the pipes
			for (int i = 0; i < content->pipe_index; i++)
			{
				if (content->end[i][READ_END] != -1)
				{
					close(content->end[i][READ_END]);
					content->end[i][READ_END] = -1; // Set to -1 after closing
				}
				if (content->end[i][WRITE_END] != -1)
				{
					close(content->end[i][WRITE_END]);
					content->end[i][WRITE_END] = -1; // Set to -1 after closing
				}
			}
            ft_exec(content, envp, fd_index);
        }
        else
        {
            // Parent process
			if (fd_index != 0)
			{
				if (content->end[fd_index - 1][READ_END] != -1)
					close(content->end[fd_index - 1][READ_END]);
				content->end[fd_index - 1][READ_END] = -1;
			}
			if (content->end[fd_index][WRITE_END] != -1)
				close(content->end[fd_index][WRITE_END]);
			content->end[fd_index][WRITE_END] = -1;
			if (fd_index == 0)
			{
				if (content->infile != -1)
					close(content->infile);
				content->infile = -1;
			}
			if (fd_index == content->pipe_index - 1)
			{
				if (content->outfile != -1)
					close(content->outfile);
				content->outfile = -1;
			}
        }
        fd_index++;
    }
	for (int i = 0; i < content->pipe_index; i++)
	{
		waitpid(content->pids[i], NULL, 0);
	}
}

void	ft_exec(t_pipe *content, char **envp, int fd_index)
{
    content->valid_path = get_cmd(content->cmd_paths, *content->cmd[fd_index]);
    if (execve(content->valid_path, content->cmd[fd_index], envp) < 0)
    {
        perror("Error: execve failed");
        for (int i = 0; i <= content->pipe_index; i++)
        {
            close(content->end[i][READ_END]);
            close(content->end[i][WRITE_END]);
        }
        free_pipex(content);
        exit(EXIT_FAILURE);
    }
}
