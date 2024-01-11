/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:38:40 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/11 22:15:06 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./libftprintf/ft_printf.h"

/*		pipex utils		*/
// int		ft_index(char *str, char c);
// int		ft_getlen(char **array);

/*		pipex functions		*/

char	*ft_pipex(char **cmds, char *output, char **env);

void	ft_free(char **ptr);

/* Reads from fd and returns `char *contents`.*/
/* Will always close `fd`.*/
char	*ft_fopen(int fd);

/* Takes in `str` and converts it into double ptr `char **cmd` for use in */
/* execve(2).*/
char	**ft_get_cmd(char *str, char *infile, char **env);

/* Executes `cmd` in seperate process thats reads from `input_fd`.*/
/* Will always close `input_fd`.*/
char	*ft_execute(char **cmd, int input_fd);

#endif
