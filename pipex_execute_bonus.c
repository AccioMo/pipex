/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:32:48 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/10 20:26:04 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_execute(char **cmd, int input_fd)
{
	int		end[2];
	int		pid;

	if (pipe(end) < 0)
		perror("pipe");
	pid = fork();
	if (pid > 0)
	{
		wait(NULL);
		close(end[1]);
		close(input_fd);
		return (ft_fopen(end[0]));
	}
	else if (pid == 0)
	{
		dup2(input_fd, 0);
		close(end[0]);
		dup2(end[1], 1);
		if (execve(*cmd, cmd, NULL) == -1)
			perror(*cmd);
	}
	else
		perror("fork");
	return (NULL);
}
