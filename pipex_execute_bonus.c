/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:32:48 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/10 00:45:34 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_execute(char **cmd, int input_fd)
{
	char	*output;
	int		end[2];
	int		pid;

	if (pipe(end) < 0)
		perror("pipe");
	pid = fork();
	if (pid > 0)
	{
		wait(NULL);
		close(end[1]);
		output = ft_fopen(end[0]);
		return (close(end[0]), output);
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
