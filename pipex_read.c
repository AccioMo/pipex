/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:38:05 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/01 18:18:33 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static char	*ft_realloc(char *istr, char *buffer)
{
	char	*str;
	int		l_istr;
	int		l_buffer;

	if (buffer == NULL)
		return (istr);
	l_istr = ft_strlen(istr);
	l_buffer = ft_strlen(buffer);
	str = (char *)malloc(sizeof(char) * (l_istr + l_buffer + 1));
	if (!str)
		return (free(istr), NULL);
	ft_strncpy(ft_strncpy(str, istr, l_istr), buffer, l_buffer);
	if (istr)
		free(istr);
	return (str);
}

static char	*ft_read(int fd, char *buffer)
{
	int	rd;

	rd = read(fd, buffer, BUFFER_SIZE);
	if (rd == 0)
	{
		free(buffer);
		return (NULL);
	}
	*(buffer + rd) = '\0';
	return (buffer);
}

char	*ft_fopen(int fd)
{
	char	*buffer;
	char	*infile;

	infile = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	buffer[BUFFER_SIZE] = '\0';
	while (buffer)
	{
		buffer = ft_read(0, buffer);
		infile = ft_realloc(infile, buffer);
		if (!infile)
			return (free(buffer), NULL);
	}
	return (infile);
}
