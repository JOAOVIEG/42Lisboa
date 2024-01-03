/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:14:17 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/03 16:33:16 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_pipe	*pipe;
	if (ac < 5)
	{
		perror("Error: wrong number of arguments");
		exit(EXIT_FAILURE);
	}
	else if (ac >= 5)
	{
		if (*envp == NULL)
		{
			perror("no environment ERROR");
			exit(EXIT_FAILURE);
		}
		ft_init_xpipe(&pipe, av, ac);
		pipex(pipe, envp, av, ac);
		free_pipex(pipe);
		return (0);
	}
}
