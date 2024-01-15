/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/15 19:02:55 by mzeggaf          ###   ########.fr       */
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
	system("leaks pipex_bonus");
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
	char	*outfile;
	int		fd;

	if (argc < 5)
		return (0);
	outfile = *(argv + argc - 1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		output = ft_here_doc(argv + 2, env);
		fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0666);
	}
	else
	{
		argv = ft_redirect_input(argv, &output);
		output = ft_pipex(argv + 2, output, env);
		fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}
	ft_putstr_fd(output, fd);
	atexit(leaks);
	atexit(print_open_fds);
	free(output);
	close(fd);
	return (0);
}
