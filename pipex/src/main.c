/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:32:18 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/08 11:47:59 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipe	*pipe;

	if (ac != 5)
	{
		perror("Error: wrong number of arguments");
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
	free_pipex(pipe);
	return (EXIT_SUCCESS);
}
