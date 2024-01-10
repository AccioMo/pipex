/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:32:48 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/09 21:41:24 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_execute(char **cmd, int *cmdin, int *cmdout)
{
	int		pid;

	pid = fork();
	if (pid > 0)
	{
		dup2(cmdout[0], 0);
		close(cmdout[1]);
		wait(NULL);
	}
	else if (pid == 0)
	{
		dup2(cmdout[1], 1);
		close(cmdout[0]);
		dup2(cmdin[0], 0);
		close(cmdin[1]);
		if (execve(*cmd, cmd, (void *) NULL) == -1)
			perror(*cmd);
	}
	else
		perror("fork");
}
