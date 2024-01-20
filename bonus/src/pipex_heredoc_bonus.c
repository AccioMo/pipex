/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:40:33 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/20 16:00:11 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	is_limiter(char *str, char *limiter)
{
	int	ret;
	int	len;

	if (!str || !limiter)
		return (0);
	len = ft_strlen(limiter);
	ret = ft_strncmp(str, limiter, len);
	if (!ret && *(str + len) == '\n')
		return (1);
	return (0);
}

static int	ft_here_doc_pipe(char **cmds, char **paths_env, int fdin)
{
	int		end[2];

	while (*(cmds + 2))
	{
		if (pipe(end) < 0)
			return (perror("pipe"), EXIT_FAILURE);
		ft_exec_cmd(*cmds, paths_env, fdin, end);
		close(fdin);
		fdin = dup(end[0]);
		if (fdin < 0)
			return (perror("dup"), EXIT_FAILURE);
		(close(end[1]), close(end[0]));
		cmds++;
	}
	if (pipe(end) < 0)
		return (perror("pipe"), EXIT_FAILURE);
	end[1] = open(*(cmds + 1), O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (end[1] < 0)
		return (perror(*(cmds + 1)), EXIT_FAILURE);
	ft_exec_cmd(*cmds, paths_env, fdin, end);
	(close(fdin), close(end[1]), close(end[0]));
	return (EXIT_SUCCESS);
}

int	ft_here_doc(char **args, char **paths_env)
{
	char	*buffer;
	char	*input;
	int		fd[2];

	input = NULL;
	buffer = NULL;
	while (is_limiter(buffer, *args) == 0)
	{
		input = ft_realloc(input, buffer);
		free(buffer);
		ft_putstr_fd("pipe heredoc> ", 1);
		buffer = get_next_line(0);
	}
	free(buffer);
	if (pipe(fd) < 0)
		return (perror("pipe"), EXIT_FAILURE);
	ft_putstr_fd(input, fd[1]);
	free(input);
	close(fd[1]);
	return (ft_here_doc_pipe(args + 1, paths_env, fd[0]));
}
