/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/02/23 19:05:49 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysctl.h>
#include <errno.h>

int	main(int argc, char *argv[], char *env[])
{
	char	**paths_env;
	int		exit_status;

	ft_input_check(argc);
	paths_env = ft_get_paths(env);
	if (!paths_env)
		return (1);
	exit_status = ft_pipex(argv + 1, paths_env);
	while (wait(NULL) > 0)
		;
	ft_free(paths_env);
	return (0);
}
