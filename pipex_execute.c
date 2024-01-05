/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:32:48 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/05 23:03:19 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_execute(char **cmd, int *end)
{
	char	*output;
	int		pid;

	pid = fork();
	if (pid > 0) // parent
	{
		dup2(end[0], 0);
		close(end[1]);
		return (ft_fopen(end[0]));
	}
	else if (pid == 0) // child
	{
		dup2(end[1], 1);
		close(end[0]);
		execve(*cmd, cmd, (void *) NULL);
		perror(*cmd);
	}
	return (NULL);
}
