/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:21:39 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/02 09:24:41 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

char	*get_path(char **envp, t_pipe *pipe)
{
	if ( *envp == NULL)
	{
		perror("ERROR envp");
		free_pipex(pipe);
		exit(EXIT_FAILURE);	
	}
	else
	{
		while (*envp && ft_strncmp("PATH", *envp, 4))
			envp++;
		if (*envp == NULL)
		{
			perror("ERROR finding PATH");
			free_pipex(pipe);
			exit(EXIT_FAILURE);	
		}
	}
	return (*envp + 5);
}

char	*get_cmd(char **cmd_paths, char *cmd)
{
	if (cmd[0] == '/')
	{
		if (access(cmd, F_OK) == 0)
			return (cmd);
		else
			perror("Error");
	}
	else
	{
		if (cmd_paths)
			return (validate_cmds(cmd_paths, cmd));
		else
			perror("Error");
	}
	return (NULL);
}

char	*validate_cmds(char **cmd_paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (cmd_paths[i])
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
