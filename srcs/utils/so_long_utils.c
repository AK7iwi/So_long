/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 03:28:46 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/11 04:25:41 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(char **map, t_error *error)
{
	uint16_t i;
	
	i = 0;
	
	while (map[i])
		free(map[i++]);
	free(map);
	free(error);
}

// void	print_map(char **map) 
// {
// 	uint16_t i = 0;
// 	while(map[i])
// 	{
// 		printf("%s\n", map[i]);
// 		i++;
// 	}
// }