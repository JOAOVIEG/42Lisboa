/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:15:03 by joaocard          #+#    #+#             */
/*   Updated: 2023/12/23 17:39:40 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../../inc/libft/libft.h"
# include <string.h>
# include <errno.h>

# define READ_END 0
# define WRITE_END 1

typedef struct s_pipe
{
	char	*paths;
	char	**cmd_paths;
	char	***cmd;
	char	*valid_path;
	int		pipe_index;
	int		infile;
	int		outfile;
	int		**end;
	pid_t	*pids;
}	t_pipe;

void	ft_init_xpipe(t_pipe **pipe, char **av, int ac);
void	free_pipex(t_pipe *pipe);
void	free_cmd(t_pipe *pipe);
void	main_init(int ac, char **av, t_pipe *pipe);
void	check_files(int infile, int outfile, t_pipe *pipe);
void	pipex(t_pipe *content, char **envp);
pid_t	child_1(t_pipe *content, char **envp, int fd_index);
pid_t	middle_child(t_pipe *content, char **envp, int fd_index);
pid_t	child_n(t_pipe *content, char **envp, int fd_index);
// void	wait_and_close_childs(t_pipe *content);
void	free_end(t_pipe *pipe);
// void	main_close(t_pipe *content);
char	*get_path(char **envp, t_pipe *pipe);
char	*get_cmd(char	**cmd_paths, char *cmd);
void	check_path(t_pipe *pipe, char **envp);
char	*validate_cmds(char **cmd_paths, char *cmd);
// void	dup_error(t_pipe *pipe);
#endif