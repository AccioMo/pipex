/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/19 18:15:52 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *env[])
{
	char	**paths_env;
	int		exit_status;

	if (argc < 5)
		return (0);
	paths_env = ft_get_paths(env);
	if (!paths_env)
		return (1);
	if (ft_strncmp(*(argv + 1), "here_doc", 8) == 0)
		exit_status = ft_here_doc(argv + 2, paths_env);
	else
		exit_status = ft_pipex(argv + 1, paths_env);
	while (wait(NULL) > 0)
		;
	ft_free(paths_env);
	return (exit_status);
}
