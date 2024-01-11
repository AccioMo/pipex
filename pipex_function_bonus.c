/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_function_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/11 18:53:30 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_pipe_to(char *content, int end[2])
{
	if (pipe(end) < 0)
		perror("pipe");
	dup2(end[1], 1);
	ft_putstr_fd(content, end[1]);
	close(end[1]);
	free(content);
	close(1);
}

char	*ft_pipex(char **cmds, char *output, char **env)
{
	char	**cmd;
	int		cmd_in[2];
	int		tmp_fd;

	tmp_fd = dup(1);
	while (*(cmds + 1))
	{
		if (!output)
			return (close(tmp_fd), exit(1), NULL);
		dup2(tmp_fd, 1);
		ft_pipe_to(output, cmd_in);
		cmd = ft_get_cmd(*cmds, NULL, env);
		output = ft_execute(cmd, cmd_in[0]);
		cmds++;
	}
	close(tmp_fd);
	return (output);
}
