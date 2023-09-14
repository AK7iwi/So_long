/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:11:47 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/14 04:24:44 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char **argv)
{
	size_t	len;

	len = ft_strlen(argv[1]);
	if (
		argv[1][len - 1] != 'r'
		|| argv[1][len - 2] != 'e'
		|| argv[1][len - 3] != 'b'
		|| argv[1][len - 4] != '.'
		)
		return (1);
	return (0);
}

void	parsing_file(int argc, char **argv, t_error *error)
{
	if (argc != 2)
		error->error_g |= ERROR_ARG;
	else if (is_ber(argv) == 1)
		error->error_g |= ERROR_BER;
}
