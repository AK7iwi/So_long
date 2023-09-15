/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_valid_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 02:49:59 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/15 11:37:33 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_valid_char_pathfinding(t_data *data, uint8_t player_x,
uint8_t player_y)
{
	return (
		data->map[player_y][player_x] == '0'
			|| data->map[player_y][player_x] == 'C'
			|| data->map[player_y][player_x] == 'E'
			);
}

bool	valid_path(t_data *data, uint8_t player_x, uint8_t player_y)
{
	if (data->map[player_y][player_x] == 'E')
		return (1);
	if (data->map[player_y][player_x] == '0'
		|| data->map[player_y][player_x] == 'C')
		data->map[player_y][player_x] *= -1;
	if (is_valid_char_pathfinding(data, player_x + 1, player_y))
		if (valid_path(data, player_x + 1, player_y))
			return (1);
	if (is_valid_char_pathfinding(data, player_x - 1, player_y))
		if (valid_path(data, player_x - 1, player_y))
			return (1);
	if (is_valid_char_pathfinding(data, player_x, player_y + 1))
		if (valid_path(data, player_x, player_y + 1))
			return (1);
	if (is_valid_char_pathfinding(data, player_x, player_y - 1))
		if (valid_path(data, player_x, player_y - 1))
			return (1);
	return (0);
}
