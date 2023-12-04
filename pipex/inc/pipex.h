/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:06:46 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/04 14:00:21 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_pipe
{
	char	*cmd; //command path
	char	**cmd_args; //command arguments
	char	*infile; //input file
	char	*outfile; //output file
	pid_t	pid1; 
	pid_t	pid2; //process ids
}	t_pipe;

void	ft_init_pipe(t_pipe **pipe);

#endif