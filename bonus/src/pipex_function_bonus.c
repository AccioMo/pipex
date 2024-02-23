/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_function_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/02/23 19:04:14 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_input_check(int argc, char *here_doc)
{
	if (argc - (ft_strncmp(here_doc, "here_doc\0", 9) == 0) < 5)
	{
		ft_putstr_fd("usage:	./pipex_bonus infile cmd1 ... cmd2 outfile\n" \
			, 2);
		ft_putstr_fd("	./pipex_bonus here_doc LIMITER cmd1 ... cmd2 outfile\n" \
			, 2);
		exit(EXIT_SUCCESS);
	}
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

static int	ft_redirect_input(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		return (perror(infile), -1);
	return (fd);
}

static int	ft_redirect_output(char **cmds, int fdin, char **paths_env)
{
	int	end[2];

	if (pipe(end) < 0)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	close(end[1]);
	end[1] = open(*(cmds + 1), O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (end[1] < 0)
	{
		close(end[0]);
		close(end[1]);
		perror(*(cmds + 1));
		return (EXIT_FAILURE);
	}
	ft_exec_cmd(*cmds, paths_env, fdin, end);
	close(fdin);
	close(end[1]);
	close(end[0]);
	return (EXIT_SUCCESS);
}

int	ft_pipex(char **cmds, char **paths_env)
{
	int		end[2];
	int		fdin;

	fdin = ft_redirect_input(*cmds++);
	while (*(cmds + 2))
	{
		if (pipe(end) < 0)
		{
			perror("pipe");
			return (EXIT_FAILURE);
		}
		ft_exec_cmd(*cmds, paths_env, fdin, end);
		close(fdin);
		fdin = dup(end[0]);
		if (fdin < 0)
		{
			perror("dup");
			return (EXIT_FAILURE);
		}
		close(end[1]);
		close(end[0]);
		cmds++;
	}
	fdin = ft_redirect_output(cmds, fdin, paths_env);
	return (fdin);
}
