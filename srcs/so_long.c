/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:17:57 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/11 04:52:33 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void so_long()
{
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;

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
    t_error *error;
	char **map;
	uint8_t	nb_lines;
    
    error = malloc(sizeof(t_error));
	if(!error)
		return(0);
	ft_bzero(error, 5);
	if(argc != 2)
		error->error |= ERROR_ARG;
	else if (is_ber(argv) == 1)
		error->error  |= ERROR_BER;
	nb_lines = count_lines(argv,error);
	if(!(error->error | 0))
	{
		map = cpy_map(argv, nb_lines,error);
		parsing_map(map, nb_lines, error);
	}
	if(!(error->error | 0))
        so_long();
	else
		parsing_msg_error(error);
	free_all(map, error);
    return(0);
}
