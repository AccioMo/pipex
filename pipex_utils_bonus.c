/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:54:56 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/11 18:54:58 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_index(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
		str++;
		i++;
	}
	return (0);
}

int	ft_getlen(char **array)
{
	int	len;

	len = 0;
	while (*array++)
		len++;
	return (len);
}

