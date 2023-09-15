/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 02:32:47 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/15 23:36:43 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	if (data->map[data->player_y - 1][data->player_x] == 'E')
	{
		if (!check_if_coll_are_present(data))
		{
			ft_putnbr_fd(++data->nb_moves, 1);
			ft_putchar_fd('\n', 1);
			return (free_mlx(data));
		}
	}
	else if (data->map[data->player_y - 1][data->player_x] != '1')
	{
		data->map[data->player_y - 1][data->player_x] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->player_y--;
		ft_putnbr_fd(++data->nb_moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_down(t_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] == 'E')
	{
		if (!check_if_coll_are_present(data))
		{
			ft_putnbr_fd(++data->nb_moves, 1);
			ft_putchar_fd('\n', 1);
			return (free_mlx(data));
		}
	}
	else if (data->map[data->player_y + 1][data->player_x] != '1')
	{
		data->map[data->player_y + 1][data->player_x] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->player_y++;
		ft_putnbr_fd(++data->nb_moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_left(t_data *data)
{
	if (data->map[data->player_y][data->player_x - 1] == 'E')
	{
		if (!check_if_coll_are_present(data))
		{
			ft_putnbr_fd(++data->nb_moves, 1);
			ft_putchar_fd('\n', 1);
			return (free_mlx(data));
		}
	}
	else if (data->map[data->player_y][data->player_x - 1] != '1')
	{
		data->map[data->player_y][data->player_x - 1] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->player_x--;
		ft_putnbr_fd(++data->nb_moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_right(t_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] == 'E')
	{
		if (!check_if_coll_are_present(data))
		{
			ft_putnbr_fd(++data->nb_moves, 1);
			ft_putchar_fd('\n', 1);
			return (free_mlx(data));
		}
	}
	else if (data->map[data->player_y][data->player_x + 1] != '1')
	{
		data->map[data->player_y][data->player_x + 1] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->player_x++;
		ft_putnbr_fd(++data->nb_moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_player(int keycode, t_data *data)
{
	if(!check_if_coll_are_present(data))
	{
		data->map[data->exit_y][data->exit_x] = 'E';
		print_map(data);
	}
	if (keycode == MOVE_UP)
		move_up(data);
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
