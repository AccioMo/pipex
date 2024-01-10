/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/08 11:09:06 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	char	*output;
	char	**cmd;
	char	**cmd2;
	int		cmdin[2];
	int		cmdout[2];
	int		fd;

	if (argc != 5)
		return (0);
	cmd = ft_get_cmd(argv[2], argv[1], env);
	if (pipe(cmdout) < 0 || pipe(cmdin) < 0)
	 	perror("pipe");
	ft_execute(cmd, cmdin, cmdout);
	wait(NULL);
	cmd2 = ft_get_cmd(argv[3], NULL, env);
	ft_execute(cmd2, cmdout, cmdin);
	wait(NULL);
	output = ft_fopen(cmdin[0]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	ft_putstr_fd(output, fd);
	close(cmdin[0]);
	close(cmdin[1]);
	close(cmdout[0]);
	close(cmdout[1]);
	close(fd);
	return (0);
}
