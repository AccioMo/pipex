/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:54:49 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/11 20:34:35 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**ft_get_paths(char **env)
{
	while (*env)
	{
		if (!ft_strncmp(*env, "PATH", 4))
			return (ft_split((*env) + 5, ':'));
		env++;
	}
	return (NULL);
}

static char	*ft_match_path(char *cmd, char **paths)
{
	char	*path;
	char	*full_path;

	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		full_path = ft_strjoin(path, cmd);
		free(path);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		paths++;
	}
	perror("Command not found");
	return (NULL);
}

static char	**ft_cmd_join(char *binary, char **args, char *infile)
{
	char	*str_cmd;
	char	**cmd;
	int		len;

	len = 0;
	while (*(args + len))
		len++;
	cmd = (char **)malloc((len + 2 + 1) * sizeof(char *));
	if (!cmd)
		return (NULL);
	*cmd++ = binary;
	while (*args)
		*cmd++ = *args++;
	*cmd++ = infile;
	*cmd = NULL;
	ft_printf("well: %s\n", *(cmd - (len + 2)));
	return (cmd - (len + 2));
}

char	**ft_get_cmd(char *full_cmd, char *infile, char **env)
{
	char	**cmd;
	char	**args;
	char	**paths;
	char	*cmd_path;

	paths = ft_get_paths(env);
	if (!paths)
		return (NULL);
	args = ft_split(full_cmd, ' ');
	cmd_path = ft_match_path(*args, paths);
	free(paths);
	if (!cmd_path)
		return (NULL);
	cmd = ft_cmd_join(cmd_path, args + 1, infile);
	return (cmd);
}
