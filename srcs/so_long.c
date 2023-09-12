
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

// void	valid_path(char **map, t_error *error)
// {
	
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void so_long()
{
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
	ft_putstr_fd("So_long", 1);
}

int main(int argc, char **argv)
{
    t_data		data;
    t_error		error;
	uint8_t		nb_lines;
    
	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&error, sizeof(t_error));
	data.error = &error;
	parsing_file(argc, argv, data.error);
	if (!data.error->error_g)
	{
		nb_lines = count_lines(argv, data.error);
		data.map = cpy_map(argv, nb_lines, data.error);
		parsing_map(&data, nb_lines);
	}
	if(!data.error->error_g)
        so_long();
	else
		parsing_msg_error(data.error);
	free_all(&data);
    return(0);
}

/* testing */

// void	fake(t_error *error) {
// 	error->error_g = 4;
// }

// void	fake2(t_data *data) {
// 	data->endian = 42;
// }

// void	fake3(t_data *data) {
// 	data->error->exit = 75;
// }

// printf("avant %d\n", error.error_g);
// fake(data.error);
// printf("apres %d\n", error.error_g);
// printf("------------\n");

// printf("avant %d\n", data.endian);
// fake2(&data);
// printf("apres %d\n", data.endian);
// printf("------------\n");

// printf("avant %d\n", data.error->exit);
// fake3(&data);
// printf("apres %d\n", data.error->exit);
// printf("------------\n");


