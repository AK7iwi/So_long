/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:35:12 by mfeldman          #+#    #+#             */
/*   Updated: 2023/08/19 04:05:21 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lignefin(char *buf)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			j = 1;
		i++;
	}
	return (j);
}

char	*ft_stock(char *stock, char *buf)
{
	size_t			i;
	size_t			j;
	char			*rest;

	i = 0;
	j = 0;
	rest = malloc(sizeof(char) * (ft_strlen(stock) + 1));
	if (!rest)
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	while (stock[j] && j < i)
	{
		rest[j] = stock[j];
		j++;
	}
	rest[j] = '\0';
	j = 0;
	while (buf[j] && stock[i])
		buf[j++] = stock[i++];
	buf[j] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	int				ret;
	char			*stock;
	char			*lignef;
	static char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = NULL;
	stock = ft_strjoin(stock, buf);
	if (!stock)
		return (free(stock), NULL);
	ret = 1;
	while (!ft_lignefin(buf) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (free(stock), NULL);
		buf[ret] = '\0';
		if (!ret && !stock[0])
			return (free(stock), NULL);
		stock = ft_strjoin(stock, buf);
	}
	lignef = ft_stock(stock, buf);
	return (free(stock), lignef);
}
