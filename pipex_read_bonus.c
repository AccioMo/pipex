/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_read_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:38:05 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/10 20:29:21 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*ft_strncpy(char *dest, char *src, int n)
{
	while (n > 0 && *src)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return (dest);
}

static char	*ft_realloc(char *istr, char *buffer, int n)
{
	char	*str;
	int		l_istr;

	if (n < 0)
		return (istr);
	l_istr = ft_strlen(istr);
	str = (char *)malloc(sizeof(char) * (l_istr + n + 1));
	if (!str)
		return (free(istr), NULL);
	ft_strncpy(ft_strncpy(str, istr, l_istr), buffer, n);
	if (istr)
		free(istr);
	return (str);
}

char	*ft_fopen(int fd)
{
	int		rd;
	char	*buffer;
	char	*contents;

	rd = 1;
	contents = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (close(fd), NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (close(fd), NULL);
	buffer[BUFFER_SIZE] = '\0';
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		contents = ft_realloc(contents, buffer, rd);
		if (!contents)
			return (close(fd), free(buffer), NULL);
	}
	close(fd);
	free(buffer);
	return (contents);
}
