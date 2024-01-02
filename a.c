/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:58:50 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/01 21:25:31 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "pipex.h"

int main(int c, char** v)
{
	int	end[2];
	pipe(end);
	dup2(1, end[1]);
	close(1);
	execve(*(v + 1), v + 1, (void *) NULL);
	char* h = ft_fopen(end[0]);
	printf("%s\n", h);
}