/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/05 23:02:59 by mzeggaf          ###   ########.fr       */
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
		if (!ft_strncmp(*env, "PATH", 4))
			return (ft_split((*env) + 5, ':'));
		env++;
	}
	return (NULL);
}

int	ft_index(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
		str++;
		i++;
	}
	return (0);
}

char	*ft_match_path(char *cmd, char **paths)
{
	char	*path;
	char	*full_path;

	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		full_path = ft_strjoin(path, cmd);
		free(path);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		paths++;
	}
	perror("Command not found");
	return (NULL);
}

int	ft_getlen(char **array)
{
	int	len;

	len = 0;
	while (*array++)
		len++;
	return (len);
}

char	**ft_cmd_join(char *binary, char **args, char *infile)
{
	char	*str_cmd;
	char	**cmd;
	int		len;

	len = 2 + ft_getlen(args);
	cmd = (char **)malloc((len + 1) * sizeof(char *));
	if (!cmd)
		return (NULL);
	*cmd++ = binary;
	while (*args)
		*cmd++ = *args++;
	*cmd++ = infile;
	*cmd = NULL;
	return (cmd - len);
}

char	**ft_get_cmd(char *full_cmd, char *infile, char **env)
{
	char	**cmd;
	char	**args;
	char	**paths;
	char	*cmd_path;

	paths = ft_get_paths(env);
	if (!paths)
		return (NULL);
	args = ft_split(full_cmd, ' ');
	cmd_path = ft_match_path(*args, paths);
	free(paths);
	if (!cmd_path)
		return (NULL);
	cmd = ft_cmd_join(cmd_path, args + 1, infile);
	return (cmd);
}

int	main(int argc, char *argv[], char *env[])
{
	char	*output;
	char	**paths;
	char	**cmd;
	int		end[2];

	// fd = open(argv[1], O_RDONLY);
	// infile = ft_fopen(fd);
	cmd = ft_get_cmd(argv[2], argv[1], env);
	// if (pipe(end) < 0)
	// 	perror("pipe");
	output = ft_execute(cmd, end);
	ft_printf("%s\n", output);
	// if (!output)
	// 	ft_abort(end);
	// 	perror("output");

	// // dup2(stdout_clone, 1);
	// pid = fork();
	// fd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	// ft_putstr_fd(output, fd);
	// ft_cmd(infile, cmd);
	// pipe();
	// execve();
	return (0);
}