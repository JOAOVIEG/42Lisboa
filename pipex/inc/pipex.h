/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:06:46 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/07 16:35:01 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ_END 0
# define WRITE_END 1

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <string.h>
# include <errno.h>

typedef struct s_pipe
{
	char	*paths;
	char	**cmd_paths;
	char	**cmd1;
	char	**cmd2;
	char	*valid_path;
	int		infile;
	int		outfile;
	int		end[2];
	pid_t	pid1;
	pid_t	pid2;
}	t_pipe;

void	ft_init_pipe(t_pipe **pipe, char **av);
void	free_pipex(t_pipe *pipe);
void	free_cmd1(t_pipe *pipe);
void	free_cmd2(t_pipe *pipe);
void	main_init(int ac, char **av, t_pipe *pipe);
void	check_files(int infile, int outfile, t_pipe *pipe);
void	pipex(t_pipe *content, char **envp);
void	child_process(t_pipe *content, char **envp);
void	child_process2(t_pipe *content, char **envp);
void	wait_and_close_childs(t_pipe *content);
void	main_close(t_pipe *content);
char	*get_path(char **envp);
char	*get_cmd(char	**cmd_paths, char *cmd);
void	check_path(t_pipe *pipe, char **envp);
char	*validate_cmds(char **cmd_paths, char *cmd);
#endif