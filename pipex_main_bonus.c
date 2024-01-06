/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/05 23:02:59 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *env[])
{
	char	*output;
	char	**cmd;
	char	**cmd2;
	int		cmdin[2];
	int		cmdout[2];
	int		fd;

	// if (argc != 5)
	// 	return (0);
	if (pipe(cmdout) < 0 || pipe(cmdin) < 0)
	 	perror("pipe");
	dup2(cmdin[1], 1);
	while (*argv)
	{
		cmd = ft_get_cmd(*argv, NULL, env);
		ft_execute(cmd, cmdin, cmdout);
		output = ft_fopen(cmdout[0]);
		ft_putstr_fd(output, cmdin[1]);
		argv++;
	}
	// cmd = ft_get_cmd(argv[2], argv[1], env);
	// ft_execute(cmd, cmdin, cmdout);
	// cmd2 = ft_get_cmd(argv[3], NULL, env);
	// ft_execute(cmd2, cmdout, cmdin);
	output = ft_fopen(cmdin[0]);
	// fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	// ft_putstr_fd(output, fd);
	ft_printf("a: %s", output);
	return (0);
}
