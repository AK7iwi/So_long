
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:17:57 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/12 02:07:20 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* check valid and same height/width of each image */
bool	img_init(t_data *data)
{
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &data->widht_per_image, &data->height_per_image);
	if (!data->wall_img)
		return (EXIT_FAILURE);
	
	data->ground_img = mlx_xpm_file_to_image(data->mlx, "./img/ground.xpm", &data->widht_per_image, &data->height_per_image);
	if (!data->ground_img)
		return (EXIT_FAILURE);
	
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm", &data->widht_per_image, &data->height_per_image);
	if (!data->exit_img)
		return (EXIT_FAILURE);
	
	data->coll_img = mlx_xpm_file_to_image(data->mlx, "./img/coll.xpm", &data->widht_per_image, &data->height_per_image);
	if (!data->coll_img)
		return (EXIT_FAILURE);
	
	data->player_img = mlx_xpm_file_to_image(data->mlx, "./img/player.xpm", &data->widht_per_image, &data->height_per_image);
	if (!data->player_img)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);

}

bool game_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (EXIT_FAILURE);
	if (!img_init(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	print_block(t_data *data, uint8_t y, uint8_t x)
{
	char c;

	c = data->map[y][x];
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_img, x * data->widht_per_image, y * data->height_per_image);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground_img, x * data->widht_per_image, y * data->height_per_image);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->coll_img, x * data->widht_per_image, y * data->height_per_image);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit_img, x * data->widht_per_image, y * data->height_per_image);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img, x * data->widht_per_image, y * data->height_per_image);
}

void	print_map(t_data *data)
{
	uint8_t i;
	uint8_t j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			print_block(data, i, j);
			j++;
		}
		i++;
	}
}

void	find_player_position(t_data *data)
{
	uint8_t i;
	uint8_t j;

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

bool	check_if_coll_are_present(t_data *data)
{
	uint8_t i;
	uint8_t j;

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

void	move_top(t_data *data)
{
	if (data->map[data->player_y - 1][data->player_x ] == 'E')
	{
		if (!check_if_coll_are_present(data))
			return (free_mlx(data));
	}
	else if (data->map[data->player_y - 1][data->player_x] != '1')
	{
		data->map[data->player_y - 1][data->player_x] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		printf("%d\n", ++data->nb_moves);
		data->player_y--;
	}
}

void	move_down(t_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] == 'E')
	{
		if (!check_if_coll_are_present(data))
			return (free_mlx(data));
	}
	else if (data->map[data->player_y + 1][data->player_x] != '1')
	{
		data->map[data->player_y + 1][data->player_x] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		printf("%d\n", ++data->nb_moves);
		data->player_y++;
	}
}

void	move_left(t_data *data)
{
	if (data->map[data->player_y][data->player_x - 1] == 'E')
	{
		if (!check_if_coll_are_present(data))
			return (free_mlx(data));
	}
	else if (data->map[data->player_y][data->player_x - 1] != '1')
	{
		data->map[data->player_y][data->player_x - 1] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		printf("%d\n", ++data->nb_moves);
		data->player_x--;
	}
}

void	move_right(t_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] == 'E')
	{
		if (!check_if_coll_are_present(data))
			return (free_mlx(data));
	}
	else if (data->map[data->player_y][data->player_x + 1] != '1')
	{
		data->map[data->player_y][data->player_x + 1] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		printf("%d\n", ++data->nb_moves);
		data->player_x++;
	}
}

void	move_player(int keycode, t_data *data)
{
	if (keycode == MOVE_UP)
		move_top(data);
	else if (keycode == MOVE_DOWN)
		move_down(data);
	else if (keycode == MOVE_LEFT)
		move_left(data);
	else if (keycode == MOVE_RIGHT)
		move_right(data);
	else if (keycode == ESC)
		free_mlx(data);
	print_map(data);
}
// add one 
void	start_game(t_data *data)
{
	find_player_position(data);
	data->mlx_win = mlx_new_window(data->mlx, 64 * data->map_len_x, 64 * data->map_len_y, "so_long");
	print_map(data);
	mlx_key_hook(data->mlx_win, (void *)move_player, data);
	mlx_hook(data->mlx_win, 17, 0, (void *)free_mlx, data);
	mlx_loop(data->mlx);
}

int main(int argc, char **argv)
{
    t_data		data;
    t_error		error;
    
	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&error, sizeof(t_error));
	data.error = &error;
	
	parsing_file(argc, argv, data.error);
	if (!data.error->error_g)
		data.map_len_y = count_lines(argv, data.error);
	if (!data.error->error_g)
		data.map = cpy_map(argv, data.map_len_y, data.error);
	if (!data.error->error_g)
		parsing_map(&data, data.map_len_y);
	if (!data.error->error_g)
	{
        if (game_init(&data))
			start_game(&data);
	}
	else
		parsing_msg_error(data.error);
	free_mlx(&data);
    return(0);
}


