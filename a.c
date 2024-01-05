/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:58:50 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/05 22:46:50 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "pipex.h"

int main(int c, char** v)
{
	char *lst[] = {"ls", "-l -a", NULL};
	execve("/bin/ls", lst, (void *) NULL);
	while (1);
}