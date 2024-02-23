/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:16:59 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/02/23 18:49:42 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_perror(char **cmd)
{
	if (errno == ENOENT)
	{
		ft_putstr_fd(*cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (errno == EACCES)
	{
		ft_putstr_fd(*cmd, 2);
		ft_putstr_fd(": permission denied\n", 2);
	}
	else
		perror(*cmd);
	ft_free(cmd);
	exit(EXIT_FAILURE);
}

static void	ft_dup_pipes(int cmd_in, int *fd_pipe)
{
	if (dup2(cmd_in, 0) < 0 || dup2(fd_pipe[1], 1) < 0)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	else
	{
		close(cmd_in);
		close(fd_pipe[1]);
		close(fd_pipe[0]);
	}
}

void	ft_exec_cmd(char *full_cmd, char **paths_env, int cmd_in, int *fd_pipe)
{
	char	**cmd;
	char	*cmd_path;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (cmd_in < 0)
			exit(EXIT_FAILURE);
		ft_dup_pipes(cmd_in, fd_pipe);
		cmd = ft_split(full_cmd, ' ');
		cmd_path = ft_match_path(*cmd, paths_env);
		if (!cmd || !cmd_path)
		{
			free(cmd_path);
			ft_free(cmd);
			exit(EXIT_FAILURE);
		}
		execve(cmd_path, cmd, NULL);
		free(cmd_path);
		ft_perror(cmd);
	}
	else if (pid < 0)
		perror("fork");
}
