/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:38:40 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/18 16:21:31 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

/* Takes in a null-terminated array of `cmds`, executes each in new */
/* execve(2) process, and outputs to file with same name as last element */
/* of the array. Returns `1` or `0`.*/
int		ft_pipex(char **cmds, char **paths_env);

/* Free a null-terminated array. */
void	ft_free(char **ptr);

/* Returns `PATH` environment variable.*/
char	**ft_get_paths(char **env);

/* Matches `command` with its binary executable. Returns path on success, */
/* `NULL` on failure. */
char	*ft_match_path(char *command, char **paths_env);

/* Executes `cmd` in new process. Reads from `fdin` and writes to `fdout`.*/
void	ft_exec_cmd(char *str_cmd, char **paths_env, int fdin, int fdout);

#endif
