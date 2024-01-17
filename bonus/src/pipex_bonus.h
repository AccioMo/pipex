/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:38:40 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/17 23:27:51 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "../../libft/libft.h"
# include "../../get_next_line/get_next_line.h"
# include "../../libftprintf/ft_printf.h"

/*		pipex functions		*/

// int		ft_redirect_input(char **cmds);

void	ft_pipex(char **cmds, char **env);

void	ft_wait(int *pids, int size);

void	ft_free(char **ptr);

char	*ft_here_doc(char **args, char **env);

/* Reads from fd and returns `char *contents`.*/
/* Will always close `fd`.*/
char	*ft_fopen(int fd);

/* Takes in `str` and converts it into double ptr `char **cmd` for use in */
/* execve(2).*/
char	**ft_get_cmd(char *str, char *infile, char **env);

/* Executes `cmd` in seperate process thats reads from `input_fd`.*/
/* Will always close `input_fd`.*/
int		ft_exec_cmd(char *str_cmd, char **env, int cmd_in, int cmd_out);

#endif
