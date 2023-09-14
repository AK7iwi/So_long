/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:44:05 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/14 06:10:02 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	img_init2(t_data *data, int verif_wpi, int verif_hpi)
{
	data->player_img = mlx_xpm_file_to_image(data->mlx, "./img/player.xpm",
			&data->widht_per_image, &data->height_per_image);
	if (!data->player_img || verif_wpi != data->widht_per_image
		|| verif_hpi != data->height_per_image)
		return (EXIT_FAILURE);
	data->coll_img = mlx_xpm_file_to_image(data->mlx, "./img/coll.xpm",
			&data->widht_per_image, &data->height_per_image);
	if (!data->coll_img || verif_wpi != data->widht_per_image
		|| verif_hpi != data->height_per_image)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	img_init(t_data *data)
{
	int	verif_wpi;
	int	verif_hpi;

	data->ground_img = mlx_xpm_file_to_image(data->mlx, "./img/ground.xpm",
			&data->widht_per_image, &data->height_per_image);
	if (!data->ground_img)
		return (EXIT_FAILURE);
	verif_wpi = data->widht_per_image;
	verif_hpi = data->height_per_image;
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm",
			&data->widht_per_image, &data->height_per_image);
	if (!data->wall_img || verif_wpi != data->widht_per_image
		|| verif_hpi != data->height_per_image)
		return (EXIT_FAILURE);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm",
			&data->widht_per_image, &data->height_per_image);
	if (!data->exit_img || verif_wpi != data->widht_per_image
		|| verif_hpi != data->height_per_image)
		return (EXIT_FAILURE);
	if (img_init2(data, verif_wpi, verif_hpi))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	m_mlx_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (EXIT_FAILURE);
	if (img_init(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
