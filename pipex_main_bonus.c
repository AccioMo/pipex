/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/10 20:33:14 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_get_cmd_in(char *output, int cmd_in[2])
{
	if (pipe(cmd_in) < 0)
		perror("pipe");
	dup2(cmd_in[1], 1);
	ft_putstr_fd(output, cmd_in[1]);
	close(cmd_in[1]);
	close(1);
}
void	ft_pipex(char **cmds, char *infile, char **env)
{
	char	**cmd;
	char	*output;
	int		cmd_in[2];
	int		tmp_fd;

	tmp_fd = dup(1);
	output = ft_fopen(open(infile, O_RDONLY));
	while (*(cmds + 1))
	{
		dup2(tmp_fd, 1);
		ft_get_cmd_in(output, cmd_in);
		cmd = ft_get_cmd(*cmds, NULL, env);
		output = ft_execute(cmd, cmd_in[0]);
		cmds++;
	}
	dup2(tmp_fd, 1);
	close(tmp_fd);
	ft_printf("a: %s", output);
	tmp_fd = open(*cmds, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	ft_putstr_fd(output, tmp_fd);
	close(tmp_fd);
}

void print_open_fds() {
    int fd;
    for (fd = 0; fd < 256; ++fd) {  // Assuming a reasonable upper limit for file descriptors
        int flags = fcntl(fd, F_GETFD);
        if (flags != -1) {
            printf("File Descriptor %d is open\n", fd);
            // You can retrieve additional information using F_GETFL and other commands
        }
    }
}

int	main(int argc, char *argv[], char *env[])
{
	char	*output;
	char	**cmd;
	char	**cmds;

	atexit(print_open_fds);
	if (argc <= 2)
		return (0);
	// if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	// 	ft_here_doc(argv[2]);
	// else
		ft_pipex(argv + 2, *(argv + 1), env);
	return (0);
}
