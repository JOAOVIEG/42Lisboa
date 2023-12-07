/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:12:43 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/07 16:46:46 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_init_pipe(t_pipe **pipe, char **av)
{
	t_pipe	*content;

	content = malloc(sizeof(t_pipe));
	if (!content)
	{
		ft_printf("Error: %s\n", strerror(errno));
		exit(EXIT_SUCCESS);
	}
	content->paths = NULL;
	content->cmd_paths = NULL;
	content->valid_path = NULL;
	content->cmd1 = ft_split(av[2], ' ');
	content->cmd2 = ft_split(av[3], ' ');
	content->infile = -1;
	content->outfile = -1;
	*pipe = content;
}

void	main_init(int ac, char **av, t_pipe *pipe)
{
	int	infile;
	int	outfile;

	infile = open(av[1], O_RDONLY);
	if (infile < 0)
	{
		ft_printf("Error: %s\n", strerror(errno));
		free_pipex(pipe);
		exit(EXIT_SUCCESS);
	}
	else
		pipe->infile = infile;
	outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		ft_printf("Error: %s\n", strerror(errno));
		free_pipex(pipe);
		exit(EXIT_SUCCESS);
	}
	else
		pipe->outfile = outfile;
	check_files(pipe->infile, pipe->outfile, pipe);
}

void	check_files(int infile, int outfile, t_pipe *pipe)
{
	if (infile < 0)
	{
		ft_printf("Error: %s\n", strerror(errno));
		free_pipex(pipe);
		exit(EXIT_SUCCESS);
	}
	if (outfile < 0)
	{
		ft_printf("Error: %s\n", strerror(errno));
		free_pipex(pipe);
		exit(EXIT_SUCCESS);
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
	if (pipe->valid_path)
		free(pipe->valid_path);
	if (pipe->cmd1)
		free_cmd1(pipe);
	if (pipe->cmd2)
		free_cmd2(pipe);
	free(pipe);
}

void	free_cmd1(t_pipe *pipe)
{
	int	i;

	i = 0;
	while (pipe->cmd1[i])
	{
		free(pipe->cmd1[i]);
		i++;
	}
	free(pipe->cmd1);
}
