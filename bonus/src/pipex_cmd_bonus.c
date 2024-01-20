/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:54:49 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/20 14:47:22 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**ft_get_paths(char **env)
{
	while (*env)
	{
		if (!ft_strncmp(*env, "PATH", 4))
			return (ft_split((*env) + 5, ':'));
		env++;
	}
	return (NULL);
}

char	*ft_match_path(char *command, char **paths_env)
{
	char	*command_path;
	char	*tmp_path;

	if (!ft_strncmp("/", command, 1))
	{
		if (access(command, F_OK) == 0)
			return (ft_strdup(""));
		return (ft_strdup(command));
	}
	while (*paths_env)
	{
		tmp_path = ft_strjoin(*paths_env, "/");
		command_path = ft_strjoin(tmp_path, command);
		free(tmp_path);
		if (!command_path)
			return (NULL);
		if (access(command_path, F_OK) == 0)
			return (command_path);
		free(command_path);
		paths_env++;
	}
	return (ft_strdup(""));
}
