/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpipe_utilis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:24:07 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/05 10:28:37 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	fd_end_alloc(t_pipe *pipe)
{
	int	i;

	i = 0;
	pipe->end = malloc(sizeof(int *) * (pipe->cmd_i));
	if (!pipe->end)
	{
		perror("end malloc ERROR");
		free_pipex(pipe);
		exit(EXIT_FAILURE);
	}
	while (i < pipe->cmd_i)
	{
		pipe->end[i] = malloc(sizeof(int) * 2);
		if (!pipe->end[i])
		{
			perror("end 2nd malloc ERROR ");
			free_pipex(pipe);
			exit(EXIT_FAILURE);
		}
		pipe->end[i][WRITE_END] = -1;
		pipe->end[i][READ_END] = -1;
		i++;
	}
}

void	cmd_alloc(t_pipe *pipe, char **av)
{
	int	cmd_i;
	int	i;

	cmd_i = 0;
	if (ft_strcmp("here_doc", av[1]) == 0)
		i = 3;
	else
		i = 2;
	pipe->cmd = (char ***)malloc(sizeof(char **) * pipe->cmd_i);
	if (!pipe->cmd)
	{
		perror("cmd malloc ERROR ");
		free_pipex(pipe);
		exit(EXIT_FAILURE);
	}
	while (cmd_i < pipe->cmd_i)
	{
		pipe->cmd[cmd_i] = ft_split(av[i], ' ');
		cmd_i++;
		i++;
	}
}

void	free_cmd_paths(t_pipe *pipe)
{
	int	i;

	i = 0;
	while (pipe->cmd_paths[i])
	{
		free(pipe->cmd_paths[i]);
		i++;
	}
	free(pipe->cmd_paths);
}
