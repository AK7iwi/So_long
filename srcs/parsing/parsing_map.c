/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:49:00 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/16 03:29:42 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verif_middles_lines(char *str, size_t len, t_error *error)
{
	size_t	len_str;

	len_str = ft_strlen(str);
	if (len_str < len)
	{
		if (str[0] != '1')
			error->error_g |= ERROR_WALL;
		error->error_g |= ERROR_RECT;
	}
	else if (len_str >= len)
	{
		if (str[0] != '1' || str[len - 1] != '1')
			error->error_g |= ERROR_WALL;
	}
}

void	verif_first_and_last_line(char *str, size_t len, t_error *error)
{
	size_t	len_str;
	size_t	len_t;
	uint8_t	i;

	i = 0;
	len_str = ft_strlen(str);
	if (len_str < len)
		len_t = len_str;
	else if (len_str >= len)
		len_t = len;
	while (i < len_t)
	{
		if (str[i] != '1')
			error->error_g |= ERROR_WALL;
		i++;
	}
	if (len_wall(str) != len)
		error->error_g |= ERROR_RECT;
}

void	parsing_map(t_data *data, uint8_t nb_lines)
{
	uint8_t	line;
	uint8_t	len;

	line = 0;
	remove_n(data->map);
	len = len_wall(data->map[line]);
	while (data->map[line])
	{
		if (line == 0 || line == nb_lines - 1)
			verif_first_and_last_line(data->map[line], len, data->error);
		else
			verif_middles_lines(data->map[line], len, data->error);
		line++;
	}
	count_ex_col_pos(data, data->error, len);
	verif_ex_col_pos(data->error);
	data->map_len_x = len;
	data->map_len_y = nb_lines;
}

void	parsing_msg_error(t_error *error)
{
	ft_putstr_fd("Error", 1);
	if (error->error_g & ERROR_ARG)
		ft_putstr_fd("- Incorrect number of argument", 1);
	if (error->error_g & ERROR_BER)
		ft_putstr_fd("- Incorrect format", 1);
	if (error->error_g & ERROR_FD)
		ft_putstr_fd("- Incorrect FD", 1);
	if (error->error_g & ERROR_EMPTY)
		ft_putstr_fd("- Incorrect map or empty map", 1);
	if (error->error_g & ERROR_RECT)
		ft_putstr_fd("- Incorrect rectangle", 1);
	if (error->error_g & ERROR_WALL)
		ft_putstr_fd("- Incorrect walls", 1);
	if (error->error_g & ERROR_POS)
		ft_putstr_fd("- Incorrect start", 1);
	if (error->error_g & ERROR_EXIT)
		ft_putstr_fd("- Incorrect exit", 1);
	if (error->error_g & ERROR_COL)
		ft_putstr_fd("- Incorrect collectibles", 1);
	if (error->error_g & ERROR_CHAR)
		ft_putstr_fd("- Incorrect characters", 1);
	if (error->error_g & ERROR_NO_VALID_PATH)
		ft_putstr_fd("- Incorrect path", 1);
}
