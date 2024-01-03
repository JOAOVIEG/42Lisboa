/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:15:03 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/03 16:37:57 by joaocard         ###   ########.fr       */
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
# include "../libft/libft.h"
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
	int		cmd_i;
	int		infile;
	int		outfile;
	int		**end;
	pid_t	*pids;
}	t_pipe;

void	ft_init_xpipe(t_pipe **pipe, char **av, int ac);
void	free_pipex(t_pipe *pipe);
void	free_cmd(char ****cmd, t_pipe *pipe);
void	main_init(int ac, char **av, t_pipe *pipe);
void	check_files(int infile, int outfile, t_pipe *pipe);
void	pipex(t_pipe *content, char **envp, char **av, int ac);
void	free_end(t_pipe *pipe);
char	*get_path(char **envp, t_pipe *pipe);
char	*get_cmd(char	**cmd_paths, char *cmd);
void	check_path(t_pipe *pipe, char **envp);
char	*validate_cmds(char **cmd_paths, char *cmd);
void	ft_exec(t_pipe *content, char **envp, int fd_index);
void	fd_end_alloc(t_pipe *pipe);
void	cmd_alloc(t_pipe *pipe, char **av);
void	free_cmd_paths(t_pipe *pipe);
void	dup_error(t_pipe *pipe);
void	pipe_construct(t_pipe *content);
void	fork_error(t_pipe *content);
void	input_redirect(t_pipe *content, int nr_pipes, char **av);
void	dup_error(t_pipe * content);
void	output_redirect(t_pipe *content, int nr_pipes, char **av, int ac);
void	close_child_pipes(t_pipe *content);
void	close_parent_pipes(t_pipe *content, int nr_pipes);
void	wait_childs(t_pipe *content);
void	exec_fail(t_pipe *content);
#endif