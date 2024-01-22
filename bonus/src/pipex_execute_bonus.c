/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:32:48 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/22 10:51:50 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_perror(char **cmd)
{
	if (errno == ENOENT)
		(ft_putstr_fd(*cmd, 2), ft_putstr_fd(": command not found\n", 2));
	else if (errno == EACCES)
		(ft_putstr_fd(*cmd, 2), ft_putstr_fd(": permission denied\n", 2));
	else
		perror(*cmd);
	ft_free(cmd);
	exit(EXIT_FAILURE);
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
		if (dup2(cmd_in, 0) < 0 || dup2(fd_pipe[1], 1) < 0)
			(perror("dup2"), exit(EXIT_FAILURE));
		(close(cmd_in), close(fd_pipe[1]), close(fd_pipe[0]));
		cmd = ft_split(full_cmd, ' ');
		cmd_path = ft_match_path(*cmd, paths_env);
		if (!cmd || !cmd_path)
			(free(cmd_path), ft_free(cmd), exit(EXIT_FAILURE));
		if (execve(cmd_path, cmd, NULL) < 0)
			(free(cmd_path), ft_perror(cmd));
	}
}
