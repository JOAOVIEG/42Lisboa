/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:32:18 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/04 14:35:03 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_init_pipe(t_pipe **pipe)
{
	t_pipe	*content;

	content = malloc(sizeof(t_pipe));
	content->cmd = NULL;
	content->cmd_args = NULL;
	content->infile = NULL;
	content->outfile = NULL;
	content->pid1 = 0;
	content->pid2 = 0;
}

void	ft_check_args(char **argv, t_pipe *pipe)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (i == 0)
			pipe->infile = argv[i];
		else if (i == 1)
			pipe->cmd = argv[i];
		else if (i == 2)
			pipe->cmd_args = ft_split(argv[i], ' ');
		else if (i == 3)
			pipe->outfile = argv[i];
		i++;
	}
}

int		main(int argc, char **argv, char **envp)
{
	t_pipe	*pipe;

	if (argc != 5)
	{
		ft_printf("Error: wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	ft_init_pipe(&pipe);
	ft_check_args(argv, pipe);
	return (0);
}