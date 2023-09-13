/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:41:14 by mfeldman          #+#    #+#             */
/*   Updated: 2023/09/13 07:42:13 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

/* gnl */
# define BUFFER_SIZE 42

/* error code */
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

/* keycode */
# define MOVE_LEFT	65361
# define MOVE_UP	65362
# define MOVE_RIGHT 65363
# define MOVE_DOWN	65364	
# define ESC	 	65307


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

	uint8_t	map_len_x;
	uint8_t	map_len_y;

	void	*mlx;
	void	*mlx_win;

	void	*wall_img;
	void	*ground_img;
	void	*exit_img;
	void	*coll_img;
	void	*player_img;

	uint8_t	player_x;
	uint8_t	player_y;
	
	uint8_t	nb_moves;

	int		height_per_image;
	int		widht_per_image;

}				t_data;

void 	parsing_file(int argc, char **argv, t_error *error);
int	    count_lines(char **argv, t_error *error);
char**  cpy_map(char **argv, int nb_lines, t_error *error);
void	parsing_map(t_data *data, uint8_t nb_lines);
void    verif_first_and_last_line(char *str, size_t len, t_error *error);
void    verif_middle_lines(char *str, size_t len, t_error *error);
void	count_ex_col_pos(char *str, t_error *error);
void	verif_ex_col_pos(t_error *error);
void	valid_path(char **mapf, t_error *error);
void    parsing_msg_error(t_error *error);

/* Utils */
void	free_map(t_data *data);
void	free_mlx(t_data *data);
int		is_ber(char **argv);
void	ft_bzero(void *s, size_t n);
int 	verif_fd(int fd, t_error *error);
void 	remove_n(char **map);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);


/* GNL */

char	*get_next_line(int fd);
char	*ft_stock(char *stock, char *buf);
int		ft_lignefin(char *buf);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

/* Game */

void 	so_long();

#endif

