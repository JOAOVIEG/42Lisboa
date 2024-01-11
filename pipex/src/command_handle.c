/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:15:57 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/09 12:49:27 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*get_path(char **envp, t_pipe *pipe)
{
	while (*envp && ft_strncmp("PATH", *envp, 4))
		envp++;
	if (*envp)
		return (*envp + 5);
	else
	{
		perror("ERROR envp");
		free_pipex(pipe);
		exit(EXIT_FAILURE);
	}
}

char	*get_cmd(char	**cmd_paths, char *cmd)
{
	if (*cmd && cmd[0] == '/')
	{
		if (access(cmd, F_OK) == 0)
			return (cmd);
		else
			perror("Error:command not found");
	}
	else
	{
		if (cmd_paths)
			return (validate_cmds(cmd_paths, cmd));
		else
			perror("Error:command not found");
	}
	return (NULL);
}

char	*validate_cmds(char **cmd_paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (*cmd && cmd_paths[i])
	{
		tmp = ft_strjoin(cmd_paths[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(tmp2, F_OK) == 0)
			return (tmp2);
		free(tmp2);
		i++;
	}
	return (NULL);
}

void	check_path(t_pipe *pipe, char **envp)
{
	pipe->paths = get_path(envp, pipe);
	if (pipe->paths)
		pipe->cmd_paths = ft_split(pipe->paths, ':');
}

void	free_cmd2(t_pipe *pipe)
{
	int	i;

	i = 0;
	while (pipe->cmd2[i])
	{
		free(pipe->cmd2[i]);
		i++;
	}
	free(pipe->cmd2);
}
