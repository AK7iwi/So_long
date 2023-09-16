/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:01:16 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/16 03:47:21 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
	ft_putchar_fd('\n', 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	b;

	b = n;
	if (b < 0)
	{
		ft_putchar_fd('-', fd);
		b *= -1;
	}
	if (b <= 9)
		ft_putchar_fd('0' + b, fd);
	else if (b > 9)
	{
		ft_putnbr_fd(b / 10, fd);
		ft_putchar_fd('0' + b % 10, fd);
	}
}

void	print_block(t_data *data, uint8_t y, uint8_t x)
{
	char	c;

	c = data->map[y][x];
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_img,
			x * data->widht_per_image, y * data->height_per_image);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->ground_img,
			x * data->widht_per_image, y * data->height_per_image);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->coll_img,
			x * data->widht_per_image, y * data->height_per_image);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit_img,
			x * data->widht_per_image, y * data->height_per_image);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img,
			x * data->widht_per_image, y * data->height_per_image);
}

void	print_map(t_data *data)
{
	uint8_t	i;
	uint8_t	j;

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
