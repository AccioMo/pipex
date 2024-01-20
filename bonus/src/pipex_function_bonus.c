/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_function_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/20 15:48:23 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	ft_redirect_input(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		return (perror(infile), -1);
	return (fd);
}

int	ft_pipex(char **cmds, char **paths_env)
{
	int		end[2];
	int		fdin;

	fdin = ft_redirect_input(*cmds++);
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
	end[1] = open(*(cmds + 1), O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (end[1] < 0)
		return (perror(*(cmds + 1)), EXIT_FAILURE);
	ft_exec_cmd(*cmds, paths_env, fdin, end);
	(close(fdin), close(end[1]), close(end[0]));
	return (EXIT_SUCCESS);
}
