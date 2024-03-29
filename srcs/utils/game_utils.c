/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:36:53 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/12 16:17:33 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_if_coll_are_present(t_data *data)
{
	uint8_t	i;
	uint8_t	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	find_exit_position(t_data *data)
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
			{
				data->exit_y = i;
				data->exit_x = j;
				data->map[data->exit_y][data->exit_x] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_player_position(t_data *data)
{
	uint8_t	i;
	uint8_t	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_y = i;
				data->player_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	**cpy_map(char **argv, int nb_lines, t_error *error)
{
	int		fd;
	char	**map;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (verif_fd(fd, error) == 1)
		return (NULL);
	map = malloc(sizeof(char *) * (nb_lines + 1));
	if (!map)
		return (close(fd), NULL);
	i = 0;
	while (i < nb_lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close (fd);
	return (map);
}

int	count_lines(char **argv, t_error *error)
{
	int		fd;
	char	*line;
	int		count_line;

	fd = open(argv[1], O_RDONLY);
	if (verif_fd(fd, error) == 1)
		return (0);
	count_line = 0;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	while (line)
	{	
		count_line++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (count_line < 3)
		return (error->error_g |= ERROR_EMPTY, 0);
	return (count_line);
}
