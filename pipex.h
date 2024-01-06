/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:38:40 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/05 22:37:08 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./libftprintf/ft_printf.h"

/*		pipex utils		*/
int		ft_index(char *str, char c);
int		ft_getlen(char **array);

/*		pipex functions		*/
char	*ft_fopen(int fd);
char	**ft_get_cmd(char *full_cmd, char *infile, char **env);
int		ft_execute(char **cmd, int *cmdin, int *cmdout);

#endif
