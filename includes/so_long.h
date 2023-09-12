/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:41:14 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/12 05:15:15 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 42
# define ERROR_ARG          0x1
# define ERROR_BER          0x2
# define ERROR_FD           0x4
# define ERROR_EMPTY        0x8
# define ERROR_RECT         0x10
# define ERROR_WALL         0x20
# define ERROR_POS	        0x40
# define ERROR_EXIT         0x80
# define ERROR_COL          0x100
# define ERROR_CHAR         0x200
# define ERROR_VALID_PATH   0x400

# include "mlx.h"
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

/* Parsing */

typedef struct s_error
{
    uint16_t    error_g;
	uint8_t		exit;
	uint8_t		position;
	uint8_t		collectibles;
}				t_error;

typedef struct	s_data 
{
	t_error *error;
	char 	**map;
	// void	*img;
	// char	*addr;
	// int		bits_per_pixel;
	// int		line_length;
	int		endian;
}				t_data;

void 	parsing_file(int argc, char **argv, t_error *error);
int	    count_lines(char **argv, t_error *error);
char**  cpy_map(char **argv, int nb_lines, t_error *error);
void	parsing_map(t_data *data, uint8_t nb_lines);
void    verif_first_and_last_line(char *str, size_t len, int line, t_error *error);
void    verif_middle_lines(char *str, size_t len, t_error *error);
void	count_ex_col_pos(char *str, t_error *error);
void	verif_ex_col_pos(t_error *error);
void	valid_path(char **mapf, t_error *error);
void    parsing_msg_error(t_error *error);

/* Parsing utils */

int		is_ber(char **argv);
void	ft_bzero(void *s, size_t n);
int 	verif_fd(int fd, t_error *error);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int 	verif_fd(int fd, t_error *error);
void	ft_bzero(void *s, size_t n);


/* GNL */

char	*get_next_line(int fd);
char	*ft_stock(char *stock, char *buf);
int		ft_lignefin(char *buf);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

/* Game */

void 	so_long();
void	free_all(t_data *data);

#endif

/* control's */

// ctrl + j - open the terminal
// alt + fleche_up/fleche_down - monter/descendre une ligne
// shift + fleche_left/fleche_right = selectionner sourligner
// shift + tab - tab sens inverse
// ctrl x - couper une ligne
// ctrl + / - commentere
// ctrl + fleche_right/fleche_left = bouger de mot en mot