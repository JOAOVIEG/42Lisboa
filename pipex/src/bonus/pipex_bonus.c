/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:20:13 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/02 14:59:14 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	pipex(t_pipe *content, char **envp, char **av, int ac)
{
    int	nr_pipes;

    nr_pipes = 0;
    check_path(content, envp);
	pipe_construct(content);
    while (nr_pipes < content->pipe_index)
    {
        content->pids[nr_pipes] = fork();
        if (content->pids[nr_pipes] < 0)
			fork_error(content);
        else if (content->pids[nr_pipes] == 0)
        {
			input_redirect(content, nr_pipes, av);
			output_redirect(content, nr_pipes, av, ac);
			close_child_pipes(content);
            ft_exec(content, envp, nr_pipes);
        }
        else
			close_parent_pipes(content, nr_pipes);
        nr_pipes++;
    }
	wait_childs(content);
}

void	ft_exec(t_pipe *content, char **envp, int nr_pipes)
{
    content->valid_path = get_cmd(content->cmd_paths, *content->cmd[nr_pipes]);
    if (execve(content->valid_path, content->cmd[nr_pipes], envp) < 0)
		exec_fail(content);
}
