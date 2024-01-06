/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/05 23:02:59 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *env[])
{
	char	*output;
	char	**cmd;
	char	**cmd2;
	int		black[2];
	int		white[2];
	int		fd;

	if (argc != 5)
		return (0);
	cmd = ft_get_cmd(argv[2], argv[1], env);
	if (pipe(white) < 0 || pipe(black) < 0)
	 	perror("pipe");
	ft_execute(cmd, black, white);
	cmd2 = ft_get_cmd(argv[3], NULL, env);
	ft_execute(cmd2, white, black);
	output = ft_fopen(black[0]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	ft_putstr_fd(output, fd);
	close(black[0]);
	close(black[1]);
	close(white[0]);
	close(white[1]);
	close(fd);
	// ft_printf("%s", output);
	return (0);
}
