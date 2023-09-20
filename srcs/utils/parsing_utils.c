/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:30:49 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/20 03:55:05 by mfeldman         ###   ########.fr       */
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

void	count_ex_col_pos(t_data *data, t_error *error)
{
	uint8_t	i;
	uint8_t	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
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

int	is_ber(char **argv)
{
	size_t	len;

	len = ft_strlen(argv[1]);
	if (
		argv[1][len - 1] != 'r'
		|| argv[1][len - 2] != 'e'
		|| argv[1][len - 3] != 'b'
		|| argv[1][len - 4] != '.'
		)
		return (1);
	return (0);
}

bool	verif_fd(int fd, t_error *error)
{
	if (fd < 0 || fd > 1024)
	{
		error->error_g |= ERROR_FILE;
		close(fd);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
