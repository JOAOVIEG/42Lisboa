/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:14:17 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/28 14:55:36 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_pipe	*pipe;
	// int i;

	// i = 0;
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
		pipex(pipe, envp, av, ac);
	}
}
