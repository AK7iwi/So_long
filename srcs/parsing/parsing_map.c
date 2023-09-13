/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:49:00 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/13 07:33:25 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    verif_middle_lines(char *map, size_t len, t_error *error)
{
	size_t len_str;

	len_str = ft_strlen(map);
	if (len_str < len)
    {	
		if(map[0] != '1') 
        	error->error_g |= ERROR_WALL;
	}
	else if(len_str >= len)
	{
		if(map[0] != '1' || map[len - 1] != '1') 
        	error->error_g |= ERROR_WALL;
	}
	if(len_str != len)
		error->error_g |= ERROR_RECT;
	count_ex_col_pos(map ,error);
}

void    verif_first_and_last_line(char *map, size_t len,t_error *error)
{
	size_t len_str;
	size_t len_t;
	size_t i;
	
    i = 0;
	len_str = ft_strlen(map); 
	if(len_str < len)
		len_t = len_str;
	else if(len_str >= len)
		len_t = len; 
    while(i < len_t - 1) 
    {
        if(map[i] != '1')
        	error->error_g |= ERROR_WALL;
        i++;
    }
	if(len_str != len)
		error->error_g |= ERROR_RECT;	
}

void	parsing_map(t_data *data, uint8_t nb_lines)
{
	uint8_t	line;
	uint8_t len;

	line = 0;
	remove_n(data->map);
	len = ft_strlen(data->map[line]);
	while (line < nb_lines)
	{
		if(line == 0 || line == nb_lines - 1)
			verif_first_and_last_line(data->map[line], len, data->error);
		else
			verif_middle_lines(data->map[line], len, data->error);
		line++;
	}
	verif_ex_col_pos(data->error);
	data->map_len_x = len;
	data->map_len_y = nb_lines;
	// if (!data->error->error_g)
		// valid_path(data->map, data->error);
}

void parsing_msg_error(t_error *error)
{
	if(error->error_g & ERROR_ARG)
		ft_putstr_fd("Error\nIncorrect Number of argument", 1);
	if(error->error_g & ERROR_BER)
		ft_putstr_fd("Error\nIncorrect Format", 1);
	if(error->error_g & ERROR_FD)
		ft_putstr_fd("Error\nIncorrect FD", 1);
	if(error->error_g & ERROR_EMPTY)
		ft_putstr_fd("Error\nIncorrect map or empty map", 1);
	if(error->error_g & ERROR_RECT)
		ft_putstr_fd("Error\nIncorrect Rect", 1);
	if(error->error_g & ERROR_WALL)
		ft_putstr_fd("Error\nInvalid Walls", 1);
	if(error->error_g & ERROR_POS)
		ft_putstr_fd("Error\nIncorrect Start", 1);		
	if(error->error_g & ERROR_EXIT)
		ft_putstr_fd("Error\nIncorrect Exit", 1);
	if(error->error_g	& ERROR_COL)
		ft_putstr_fd("Error\nIncorrect Collectibles", 1);
	if(error->error_g & ERROR_CHAR)
		ft_putstr_fd("Error\nIncorrect Char", 1);
	
}
