/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_function_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/17 23:55:47 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free(char **ptr)
{
	char	**hold;

	hold = ptr;
	if (!ptr)
		return ;
	while (*ptr)
		free(*ptr++);
	free(hold);
}

// int	ft_redirect_input(char **cmds)
// {
// 	int	fd;


// 	if (fd < 0)
// 		return (perror(*cmds), -1);
// 	return (fd);
// }

void	ft_pipex(char **cmds, char **env)
{
	char	*output;
	int		end[2];
	int		fdin;

	fdin = open(*cmds++, O_RDONLY);
	while (*(cmds + 1))
	{
		if (pipe(end) < 0)
			return (perror("pipe"));
		printf("%d cmd: %s\n", fdin, *cmds);
		if (ft_exec_cmd(*cmds, env, fdin, end[1]) < 0)
			return (perror(*cmds));
		close(fdin);
		fdin = dup(end[0]);
		if (fdin < 0)
			return (perror("dup"));
		(close(end[1]), close(end[0]));
		cmds++;
	}
	output = ft_fopen(fdin);
	fdin = open(*cmds, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	ft_putstr_fd(output, fdin);
	close(fdin);
}
