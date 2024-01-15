/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/15 19:06:00 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	char	*output;
	char	*outfile;
	int		fd;

	if (argc != 5)
		return (0);
	outfile = *(argv + argc - 1);
	argv = ft_redirect_input(argv, &output);
	output = ft_pipex(argv + 2, output, env);
	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	ft_putstr_fd(output, fd);
	free(output);
	close(fd);
	return (0);
}
