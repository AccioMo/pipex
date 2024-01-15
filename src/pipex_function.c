/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/15 18:18:20 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	ft_free(char **ptr)
{
	char	**hold;

	hold = ptr;
	if (!ptr)
		return ;
	while (*ptr)
		free(*ptr++);
	free(hold);
}

char	**ft_redirect_input(char **argv, char **output)
{
	if (access(*(argv + 1), F_OK) == -1)
	{
		perror(*(argv + 1));
		argv++;
	}
	else
	{
		*output = ft_fopen(open(*(argv + 1), O_RDONLY));
		if (!*output)
			exit(1);
	}
	return (argv);
}

char	*ft_pipex(char **cmds, char *output, char **env)
{
	int		cmd_in[2];
	int		tmp_fd;

	tmp_fd = dup(1);
	while (*(cmds + 1))
	{
		ft_pipe_to(output, cmd_in);
		output = ft_execute(*cmds, cmd_in[0], env);
		dup2(tmp_fd, 1);
		cmds++;
	}
	dup2(tmp_fd, 1);
	close(tmp_fd);
	return (output);
}
