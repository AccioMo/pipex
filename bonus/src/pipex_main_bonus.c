/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/18 12:34:11 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// void	print_open_fds(void)
// {
// 	int	flags;
// 	int	fd;

// 	fd = 0;
// 	while (fd < 256)
// 	{
// 		flags = fcntl(fd, F_GETFD);
// 		if (flags != -1)
// 			printf("File Descriptor %d is open\n", fd);
// 		fd++;
// 	}
// }

// void	leaks(void)
// {
// 	system("leaks pipex_bonus");
// }

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
	// atexit(leaks);
	// atexit(print_open_fds);
	return (exit_status);
}
