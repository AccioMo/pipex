/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:40:33 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/11 20:41:28 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	is_limiter(char *str, char *limiter)
{
	int	ret;
	int	len;

	if (!str || !limiter)
		return (0);
	len = ft_strlen(limiter);
	ret = ft_strncmp(str, limiter, len);
	if (!ret && *(str + len) == '\n')
		return (1);
	return (0);
}

char	*ft_here_doc(char **args, char **env)
{
	char	*buffer;
	char	*input;

	input = NULL;
	buffer = NULL;
	while (is_limiter(buffer, *args) == 0)
	{
		input = ft_realloc(input, buffer);
		free(buffer);
		ft_putstr("pipe heredoc> ");
		buffer = get_next_line(0);
	}
	free(buffer);
	return (ft_pipex(args + 1, input, env));
}
