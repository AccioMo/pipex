/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/11 21:44:04 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_open_fds(void)
{
	int	flags;
	int	fd;

	fd = 0;
	while (fd < 256)
	{
		flags = fcntl(fd, F_GETFD);
		if (flags != -1)
			printf("File Descriptor %d is open\n", fd);
		fd++;
	}
}

void	leaks(void)
{
	system("leaks pipex");
}

int	ft_empty_input(char **argv)
{
	while (*argv)
	{
		if (ft_strlen(*argv) == 0)
			return (0);
		argv++;
	}
	return (1);
}

int	main(int argc, char *argv[], char *env[])
{
	char	*output;
	int		fd;

	// atexit(print_open_fds);
	// atexit(leaks);
	if (argc < 5)
		return (0);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		output = ft_here_doc(argv + 2, env);
		fd = open(*(argv + argc - 1), O_WRONLY | O_CREAT | O_APPEND, 0666);
	}
	else
	{
		output = ft_pipex(argv + 2, ft_fopen(open(*(argv + 1), O_RDONLY)), env);
		fd = open(*(argv + argc - 1), O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}
	ft_putstr_fd(output, fd);
	free(output);
	close(fd);
	return (0);
}
