/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/10 01:02:38 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_get_cmd_in(char *output, int cmd_in[2])
{
	if (pipe(cmd_in) < 0)
	 	perror("pipe");
	dup2(cmd_in[1], 1);
	write(cmd_in[1], output, ft_strlen(output));
	close(cmd_in[1]);
	close(1);
}

int	main(int argc, char *argv[], char *env[])
{
	char	*output;
	char	**cmd;
	char	**cmds;
	int		cmd_in[2];
	int		stdout_clone;

	if (argc <= 2)
		return (0);
	stdout_clone = dup(1);
	// close(cmdin[0]);
	cmds = (argv + 2);
	argc -= 3;
	if (pipe(cmd_in) < 0)
	 	perror("pipe");
	cmd = ft_get_cmd(*cmds, argv[1], env);
	output = ft_execute(cmd, 0);
	close(cmd_in[0]);
	// write(stdout_clone, "\n> ", 3);
	// write(stdout_clone, output, ft_strlen(output));
	cmds++;
	while (argc > 1)
	{
		ft_get_cmd_in(output, cmd_in); // here we make stdout our bitch
		cmd = ft_get_cmd(*cmds, NULL, env);
		output = ft_execute(cmd, cmd_in[0]);
		close(cmd_in[0]);
		argc--;
		cmds++;
	}
	dup2(stdout_clone, 1);
	ft_printf("a: %s", output);
	return (0);
}
