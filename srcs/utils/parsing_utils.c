/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:30:49 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/16 03:47:09 by mfeldman         ###   ########.fr       */
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

void	count_ex_col_pos(t_data *data, t_error *error, uint8_t len)
{
	uint8_t	i;
	uint8_t	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && j < len)
		{
			if (data->map[i][j] == 'E')
				error->exit ++;
			else if (data->map[i][j] == 'P')
				error->position++;
			else if (data->map[i][j] == 'C')
				error->collectibles++;
			else if (data->map[i][j] != 'E' && data->map[i][j] != 'P' &&
					data->map[i][j] != 'C' && data->map[i][j] != '1' &&
					data->map[i][j] != '0')
				error->error_g |= ERROR_CHAR;
			j++;
		}
		i++;
	}
}

uint8_t	len_wall(char *str)
{
	uint8_t	len;
	uint8_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			break ;
		i++;
	}
	len = i;
	return (len);
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
