/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/03 00:31:25 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	ft_cmd(char *file, char **cmd)
// {
// 	char	**args;
// 	int		len;

// 	if (!ft_strnstr(cmd, "/bin/", -1))
// 		ft_strjoin("/bin/", cmd);
// 	execve(*cmd, cmd, (void *) NULL);
// }

char	**ft_get_paths(char **env)
{
	while (*env)
	{
		if (ft_strnstr(*env, "PATH", 5))
			return (ft_split(*(env + 5), ':'));
		env++;
	}
	return (NULL);
}

int	main(int argc, char *argv[], char *env[])
{
	char	*infile;
	// char	*outfile;
	char	*paths;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	infile = ft_fopen(fd);
	// cmd = ft_split(argv[2], ' ');
	paths = ft_get_paths(env);
	while (*paths)
		ft_printf("%s\n", *paths++);
	// ft_cmd(infile, cmd);
	// pipe();
	// execve();
	return (0);
}