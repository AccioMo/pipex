/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:32:48 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/05 23:03:19 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_execute(char **cmd, int *black, int *white)
{
	char	*output;
	int		pid;

	pid = fork();
	if (pid > 0) // parent
	{
		dup2(white[0], 0);
		close(white[1]);
		
	}
	else if (pid == 0) // child
	{
		dup2(white[1], 1);
		close(white[0]);
		dup2(black[0], 0);
		close(black[1]);
		execve(*cmd, cmd, (void *) NULL);
		perror(*cmd);
	}
	else
		perror("fork");
}
