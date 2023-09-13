/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 03:28:46 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/13 07:34:53 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	uint8_t i;
	
	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
}

void	free_mlx(t_data *data)
{
	if (data->map)
		free_map(data);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->wall_img)
		mlx_destroy_image(data->mlx, data->wall_img);
	if (data->coll_img)
		mlx_destroy_image(data->mlx, data->coll_img);
	if (data->ground_img)
		mlx_destroy_image(data->mlx, data->ground_img);
	if (data->player_img)
		mlx_destroy_image(data->mlx, data->player_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx, data->exit_img);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	
	exit(0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
	ft_putchar_fd('\n', 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str = 0;
		str++;
		n--;
	}
}
