/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/11 22:12:16 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	char	*output;
	int		fd;

	if (argc != 5)
		return (0);
	output = ft_pipex(argv + 2, ft_fopen(open(*(argv + 1), O_RDONLY)), env);
	fd = open(*(argv + argc - 1), O_WRONLY | O_CREAT | O_TRUNC, 0666);
	ft_putstr_fd(output, fd);
	free(output);
	close(fd);
	return (0);
}
