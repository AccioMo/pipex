/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/18 16:32:09 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static void	ft_perror(char **cmd)
{
	if (errno == ENOENT)
		(ft_putstr_fd(*cmd, 2), ft_putstr_fd(": command not found\n", 2));
	else if (errno == EACCES)
		(ft_putstr_fd(*cmd, 2), ft_putstr_fd(": permission denied\n", 2));
	else
		perror(*cmd);
	ft_free(cmd);
	exit(EXIT_FAILURE);
}

void	ft_exec_cmd(char *full_cmd, char **paths_env, int cmd_in, int cmd_out)
{
	char	**cmd;
	char	*cmd_path;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (cmd_in < 0)
			exit(EXIT_FAILURE);
		if (dup2(cmd_in, 0) < 0 || dup2(cmd_out, 1) < 0)
			(perror("dup2"), exit(EXIT_FAILURE));
		cmd = ft_split(full_cmd, ' ');
		cmd_path = ft_match_path(*cmd, paths_env);
		if (!cmd || !cmd_path)
			(free(cmd_path), ft_free(cmd), exit(EXIT_FAILURE));
		if (execve(cmd_path, cmd, NULL) < 0)
			(free(cmd_path), ft_perror(cmd));
	}
}

int	ft_pipex(char **cmds, char **paths_env)
{
	int		end[2];
	int		fdin;
	int		fdout;

	fdin = ft_redirect_input(*cmds++);
	while (*(cmds + 2))
	{
		if (pipe(end) < 0)
			return (perror("pipe"), EXIT_FAILURE);
		ft_exec_cmd(*cmds, paths_env, fdin, end[1]);
		close(fdin);
		fdin = dup(end[0]);
		if (fdin < 0)
			return (perror("dup"), EXIT_FAILURE);
		(close(end[1]), close(end[0]));
		cmds++;
	}
	fdout = open(*(cmds + 1), O_WRONLY | O_CREAT | O_TRUNC, 0666);
	ft_exec_cmd(*cmds, paths_env, fdin, fdout);
	ft_free(paths_env);
	(close(fdin), close(fdout));
	return (EXIT_SUCCESS);
}
