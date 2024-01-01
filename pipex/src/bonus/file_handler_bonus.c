/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:55:53 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/01 21:18:53 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	ft_init_xpipe(t_pipe **pipe, char **av, int ac)
{
    t_pipe	*content;
    int		fd_index;
    int		i;
    int		j;

    content = malloc(sizeof(t_pipe));
    if (!content)
    {
        perror("Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    content->pipe_index = ac - 3;
    fd_index = 0;
    i = 2;
    j = 0;
    content->paths = NULL;
    content->cmd_paths = NULL;
    content->valid_path = NULL;
    content->pids = (pid_t *)malloc(sizeof(pid_t) * content->pipe_index);
    content->end = malloc(sizeof(int*) * (content->pipe_index));
    if (!content->end)
    {
        perror("end malloc ERROR ");
        exit(EXIT_FAILURE);		
    }
    while (j < content->pipe_index)
    {
        content->end[j] = malloc(sizeof(int) * 2);
        if (!content->end[j])
        {
            perror("end 2nd malloc ERROR ");
            exit(EXIT_FAILURE);
        }
		content->end[j][WRITE_END] = -1;
        content->end[j][READ_END] = -1;
        j++;
    }
    content->cmd = (char ***)malloc(sizeof(char **) * content->pipe_index);
    if(!content->cmd)
    {
        perror("cmd malloc ERROR ");
        exit(EXIT_FAILURE);		
    }
    while (fd_index < content->pipe_index)
    {
        content->cmd[fd_index] = ft_split(av[i], ' ');
        fd_index++;
        i++;
    }
    content->infile = -1;
    content->outfile = -1;
    *pipe = content;
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
	if(pipe->cmd)
		free_cmd(&(pipe->cmd), pipe);
	if (pipe->valid_path)
		free(pipe->valid_path);
	if (pipe->pids)
		free(pipe->pids);
	if (pipe->end)
	{
		if (*(pipe->end))
			free_end(pipe);
		else
			free(pipe->end);
	}
	free(pipe);
}

void	free_cmd(char ****cmd, t_pipe *pipe)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < pipe->pipe_index)
	{
		j = 0;
		while ((*cmd)[i][j])
		{
			free((*cmd)[i][j]);
			j++;
		}
		free((*cmd)[i]);
		i++;
	}
	free(*cmd);
	*cmd = NULL;
}
void	free_end(t_pipe *pipe)
{
	int	i;

	i = 0;
	while (i < pipe->pipe_index)
	{
		free(pipe->end[i]);
		i++;
	}
	free(pipe->end);
}

