/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:12:43 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/06 23:17:40 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_init_pipe(t_pipe **pipe)
{
	t_pipe	*content;

	content = malloc(sizeof(t_pipe));
	if (!content)
	{
		ft_printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	content->paths = NULL;
	content->cmd_paths = NULL;
	content->cmd = NULL;
	content->cmd_args = NULL;
	content->infile = -1;
	content->outfile = -1;
	*pipe = content;
}

void	main_init(int ac, char **av, t_pipe *pipe)
{
	int infile;
	int outfile;
	
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
	{
		ft_printf("Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
		pipe->infile = infile;
	outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		ft_printf("Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
		pipe->outfile = outfile;
	check_files(pipe->infile, pipe->outfile);
}

void	check_files(int infile, int outfile)
{
	if (infile < 0)
	{
		ft_printf("Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (outfile < 0)
	{
		ft_printf("Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
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
	if (pipe->cmd)
		free(pipe->cmd);
	if (pipe->cmd_args)
	{
		i = 0;
		while (pipe->cmd_args[i])
		{
			free(pipe->cmd_args[i]);
			i++;
		}
		free(pipe->cmd_args);
	}
	free(pipe);
}
