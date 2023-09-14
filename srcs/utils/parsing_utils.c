/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:30:49 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/14 04:42:41 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verif_ex_col_pos(t_error *error)
{
	if (error->exit != 1)
		error->error_g |= ERROR_EXIT;
	if (error->position != 1)
		error->error_g |= ERROR_POS;
	if (error->collectibles < 1)
		error->error_g |= ERROR_COL;
}

void	count_ex_col_pos(char *str, t_error *error)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str) - 1)
	{
		if (str[i] == 'E')
			error->exit ++;
		else if (str[i] == 'P')
			error->position++;
		else if (str[i] == 'C')
			error->collectibles++;
		else if (str[i] != 'E' && str[i] != 'P' && str[i] != 'C'
			&& str[i] != '1' && str[i] != '0')
			error->error_g |= ERROR_CHAR;
		i++;
	}
}

void	remove_n(char **map)
{
	uint8_t	i;
	uint8_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n' || map[i][j] == '\r')
				map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

bool	verif_fd(int fd, t_error *error)
{
	if (fd < 0 || fd > 1024)
	{
		error->error_g |= ERROR_FD;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
