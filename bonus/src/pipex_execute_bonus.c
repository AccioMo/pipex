/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:32:48 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/17 23:57:30 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// static void	ft_child(char *str_cmd, int *end, int cmd_in, char **env)
// {
// 	int		dev_null_fd;


// }

void	ft_null_fd(int fd)
{
	int	dev_null_fd;

	if (fd > 0)
		dup2(fd, 0);
	else
	{
		dev_null_fd = open("/dev/null", O_RDONLY);
		if (dev_null_fd == -1)
		{
			perror("/dev/null");
			return ;
		}
		dup2(dev_null_fd, 0);
		close(dev_null_fd);
	}
}

int	ft_exec_cmd(char *str_cmd, char **env, int cmd_in, int cmd_out)
{
	char	**cmd;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		cmd = ft_get_cmd(str_cmd, NULL, env);
		if (!cmd)
			return (-1);
		if (dup2(cmd_in, 0) < 0 || dup2(cmd_out, 1) < 0)
			return (perror("dup2"), -1);
		// ft_null_fd(cmd_in);
		execve(*cmd, cmd, NULL);
		perror(*cmd);
	}
	return (pid);
}
