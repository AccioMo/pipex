/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:32:48 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/15 18:56:20 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*ft_child_process(char *cmds, int end[2], int input_fd, char **env)
{
	char	**cmd;

	cmd = ft_get_cmd(cmds, NULL, env);
	if (!cmd)
		return (close(input_fd), exit(1), NULL);
	dup2(input_fd, 0);
	close(end[0]);
	dup2(end[1], 1);
	execve(*cmd, cmd, NULL);
	return (perror(*cmd), NULL);
}

char	*ft_execute(char *cmds, int input_fd, char **env)
{
	char	*output;
	int		end[2];
	int		pid;

	if (pipe(end) < 0)
		return (perror("pipe"), NULL);
	pid = fork();
	if (pid > 0)
	{
		wait(NULL);
		close(input_fd);
		close(end[1]);
		output = ft_fopen(end[0]);
		return (output);
	}
	else if (pid == 0)
	{
		output = ft_child_process(cmds, end, input_fd, env);
		return (output);
	}
	else
		return (perror("fork"), NULL);
}
