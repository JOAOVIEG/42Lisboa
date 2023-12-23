/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:14:17 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/23 16:55:40 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_pipe	*pipe;
	int i;

	i = 0;
	if (ac < 5)
	{
		perror("Error: wrong number of arguments");
		exit(EXIT_FAILURE);
	}
	else if (ac >= 5)
	{
		if (*envp == NULL)
		{
			perror("Error: no environment");
			exit(EXIT_FAILURE);
		}
		if (ft_strcmp("here_doc", av[1]) == 0)
		{
			//handle heredoc	
		}
		ft_init_xpipe(&pipe, av, ac);
		main_init(ac, av, pipe);
		pipex(pipe, envp);
		while (i < pipe->pipe_index)
		{
			close(pipe->end[i][READ_END]);
			close(pipe->end[i][WRITE_END]);
		}
		i = 0;
		while (i < pipe->pipe_index)
		{
			waitpid(pipe->pids[i], NULL, 0);
		}
		free_pipex(pipe);
	}
}
