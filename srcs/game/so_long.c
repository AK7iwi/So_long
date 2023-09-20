/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:17:57 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/20 05:52:05 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_data *data)
{
	find_exit_position(data);
	data->mlx_win = mlx_new_window(data->mlx,
			data->widht_per_image * data->map_len_x,
			data->height_per_image * data->map_len_y, "so_long");
	print_map(data);
	mlx_key_hook(data->mlx_win, (void *)move_player, data);
	mlx_hook(data->mlx_win, 17, 0, (void *)free_mlx, data);
	mlx_loop(data->mlx);
}

void	prestart_game(t_data *data, char **argv)
{
	if (!data->error->error_g)
		data->map_len_y = count_lines(argv, data->error);
	if (!data->map_len_y)
		return ;
	if (!data->error->error_g)
		data->map = cpy_map(argv, data->map_len_y, data->error);
	if (!data->map)
		return ;
	if (!data->error->error_g)
		parsing_map(data, data->map_len_y);
	if (!data->error->error_g)
		if (is_valid_path(data))
			data->error->error_g |= ERROR_NO_VALID_PATH;
	if (!data->error->error_g)
		reset_matrix_map(data);
}

void	parsing_file(int argc, char **argv, t_error *error)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fd > 1024)
		error->error_g |= ERROR_FILE;
	close (fd);
	if (argc != 2)
		error->error_g |= ERROR_ARG;
	if (is_ber(argv))
		error->error_g |= ERROR_BER;
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_error	error;

	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&error, sizeof(t_error));
	data.error = &error;
	parsing_file(argc, argv, data.error);
	if (data.error->error_g)
	{
		parsing_msg_error(data.error);
		return (0);
	}
	prestart_game(&data, argv);
	if (!data.error->error_g)
	{
		if (!m_mlx_init(&data))
			start_game(&data);
	}
	else
		parsing_msg_error(data.error);
	free_mlx(&data);
	return (0);
}
