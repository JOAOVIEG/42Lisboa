/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:32:18 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/09 14:43:58 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < (ac - 1))
	{
		if (*av[i] == '\0')
		{
			perror("Error usage: invalid arguments");
		}
		i++;
	}
}

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
		perror("Error usage: ./pipex file1 cmd1 cmd2 file2");
		exit(EXIT_FAILURE);
	}
	if (*envp == NULL)
	{
		perror("No environment ERROR");
		exit(EXIT_FAILURE);
	}
	check_args(ac, av);
	ft_init_pipe(&pipe, av);
	pipex(pipe, envp, av, ac);
	wait_and_close_childs(pipe);
	main_close(pipe);
	free_pipex(pipe);
	return (EXIT_SUCCESS);
}
