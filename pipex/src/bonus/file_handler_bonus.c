/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:55:53 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/03 16:39:07 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	ft_init_xpipe(t_pipe **pipe, char **av, int ac)
{
    t_pipe	*content;
	
    content = malloc(sizeof(t_pipe));
    if (!content)
    {
        perror("Error: malloc failed");
        exit(EXIT_FAILURE);
    }
	if (strcmp("here_doc", av[1]) == 0)
		content->cmd_i = ac - 4;
    else
	content->cmd_i = ac - 3;
    content->paths = NULL;
    content->cmd_paths = NULL;
    content->valid_path = NULL;
    content->pids = (pid_t *)malloc(sizeof(pid_t) * content->cmd_i);
	if (!content->pids)
	{
		perror("end malloc ERROR");
		free_pipex(content);
        exit(EXIT_FAILURE);	
	}
	fd_end_alloc(content);
	cmd_alloc(content, av);
    content->infile = -1;
    content->outfile = -1;
    *pipe = content;
}
void	free_pipex(t_pipe *pipe)
{
	if (pipe->paths)
		pipe->paths = NULL;
	if (pipe->cmd_paths)
	{
		free_cmd_paths(pipe);
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
	while (i < pipe->cmd_i)
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
	while (i < pipe->cmd_i)
	{
		free(pipe->end[i]);
		i++;
	}
	free(pipe->end);
}

