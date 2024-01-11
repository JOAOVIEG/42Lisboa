/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:20:13 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/08 17:32:58 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	pipex(t_pipe *content, char **envp, char **av, int ac)
{
	int	cmd_i;

	cmd_i = 0;
	check_path(content, envp);
	pipe_construct(content);
	while (cmd_i < content->cmd_i)
	{
		content->pids[cmd_i] = fork();
		if (content->pids[cmd_i] < 0)
			fork_error(content);
		else if (content->pids[cmd_i] == 0)
		{
			input_redirect(content, cmd_i, av);
			output_redirect(content, cmd_i, av, ac);
			close_child_pipes(content);
			ft_exec(content, envp, cmd_i);
		}
		else
			close_parent_pipes(content, cmd_i);
		cmd_i++;
	}
	wait_childs(content);
}

void	ft_exec(t_pipe *content, char **envp, int cmd_i)
{
	content->valid_path = get_cmd(content->cmd_paths, *content->cmd[cmd_i]);
	if (!content->valid_path)
		command_error(content);
	else if (content->valid_path)
	{
		if (execve(content->valid_path, content->cmd[cmd_i], envp) < 0)
			exec_fail(content);
	}
}
