/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:32:18 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/07 16:46:38 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipe	*pipe;

	if (ac != 5)
	{
		ft_printf("Error: wrong number of arguments\n");
		exit(EXIT_SUCCESS);
	}
	if (!envp)
	{
		ft_printf("Error: no environment\n");
		exit(EXIT_SUCCESS);
	}
	ft_init_pipe(&pipe, av);
	main_init(ac, av, pipe);
	pipex(pipe, envp);
	free_pipex(pipe);
	return (0);
}
