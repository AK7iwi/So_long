/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:11:47 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/12 05:19:38 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **cpy_map(char **argv, int nb_lines, t_error *error)
{
	int 	fd;
	char	**map;
	uint8_t i;
	
	fd = open(argv[1], O_RDONLY);
	if (verif_fd(fd, error) == 1)
		return(NULL);
	i = 0;
	map = malloc(sizeof(char *) * (nb_lines + 1));
	map[i] = get_next_line(fd);
	while(++i < nb_lines + 1)
		map[i] = get_next_line(fd);
	return(map);
}

int	count_lines(char **argv, t_error *error)
{
	int 	fd;
	char	*str;
	uint8_t	line;
	
	fd = open(argv[1], O_RDONLY);
	if (verif_fd(fd, error) == 1)
		return(-1);
	line = 0; 
	str = get_next_line(fd);
	if(!str)
		error->error_g |= ERROR_EMPTY;
	while (str)
	{	
		line++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	if(line < 3)
		error->error_g |= ERROR_EMPTY;
	return (line);
}

int		is_ber(char **argv)
{
	size_t len;

	len = ft_strlen(argv[1]);
	if (
		argv[1][len - 1] != 'r'
		|| argv[1][len - 2] != 'e'
		|| argv[1][len - 3] != 'b'
		|| argv[1][len - 4] != '.'
		)
		return(1);
	return (0);
}

void parsing_file(int argc, char **argv, t_error *error)
{
	if(argc != 2)
		error->error_g |= ERROR_ARG;
	else if (is_ber(argv) == 1)
		error->error_g  |= ERROR_BER;
}
