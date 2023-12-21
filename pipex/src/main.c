/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:32:18 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/21 17:02:03 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	dup_error(t_pipe *pipe)
{
	perror("dup2");
	free_pipex(pipe);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av, char **envp)
{
	t_pipe	*pipe;

	if (ac != 5)
	{
		perror("Error: wrong number of arguments");
		perror("Usage: ./pipex file1 cmd1 cmd2 file2");
		exit(EXIT_FAILURE);
	}
	if (!envp)
	{
		perror("Error: no environment");
		exit(EXIT_FAILURE);
	}
	ft_init_pipe(&pipe, av);
	main_init(ac, av, pipe);
	pipex(pipe, envp);
	wait_and_close_childs(pipe);
	main_close(pipe);
	free_pipex(pipe);
	return (EXIT_SUCCESS);
}
