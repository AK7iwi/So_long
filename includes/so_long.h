/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:41:14 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/11 22:36:10 by mfeldman         ###   ########.fr       */
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

/* Gnl */
# define BUFFER_SIZE 42

/* Error code */
# define ERROR_ARG				0x1
# define ERROR_FILE				0x2
# define ERROR_BER				0x4
# define ERROR_EMPTY			0x8
# define ERROR_RECT				0x10
# define ERROR_WALL				0x20
# define ERROR_POS				0x40
# define ERROR_EXIT				0x80
# define ERROR_COL				0x100
# define ERROR_CHAR				0x200
# define ERROR_NO_VALID_PATH	0x400

/* Keycode */
# define MOVE_LEFT	65361
# define MOVE_UP	65362
# define MOVE_RIGHT 65363
# define MOVE_DOWN	65364	
# define ESC	 	65307

typedef struct s_error
{
	uint16_t	error_g;
	uint8_t		exit;
	uint8_t		position;
	uint8_t		collectibles;
}				t_error;

typedef struct s_data
{
	t_error	*error;
	char	**map;

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
	uint8_t	exit_x;
	uint8_t	exit_y;
	uint8_t	coll;
	int		nb_moves;
	int		height_per_image;
	int		widht_per_image;

}				t_data;

/* GNL */
char	*get_next_line(int fd);
char	*ft_stock(char *stock, char *buf);
int		ft_lignefin(char *buf);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

/*Utils Game*/
int		count_lines(char **argv, t_error *error);
char	**cpy_map(char **argv, int nb_lines, t_error *error);
void	find_player_position(t_data *data);
void	reset_matrix_map(t_data *data);
void	print_map(t_data *data);
void	print_block(t_data *data, uint8_t y, uint8_t x);
void	find_exit_position(t_data *data);
bool	check_if_coll_are_present(t_data *data);
void	free_map(t_data *data);
void	free_mlx(t_data *data);

/*Game */
void	start_game(t_data *data);
void	move_player(int keycode, t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_up(t_data *data);

/* Init game */
void	ft_bzero(void *s, size_t n);
void	prestart_game(t_data *data, char **argv);
bool	m_mlx_init(t_data *data);
bool	img_init(t_data *data);
bool	img_init2(t_data *data, int verif_wpi, int verif_hpi);

/* Valid path parsing*/
bool	valid_path_exit(t_data *data, uint8_t player_x, uint8_t player_y);
bool	is_valid_char_pathfinding(t_data *data, uint8_t player_x,
			uint8_t player_y);
bool	valid_path_coll(t_data *data, uint8_t player_x, uint8_t player_y);
bool	is_valid_path(t_data *data);

/* Utils Parsing */
bool	verif_fd(int fd, t_error *error);
int		is_ber(char **argv);
void	remove_n(char **map);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

/* Parsing */
void	parsing_file(int argc, char **argv, t_error *error);
void	parsing_map(t_data *data, uint8_t nb_lines);
void	verif_first_and_last_line(char *str, size_t len, t_error *error);
void	verif_middles_lines(char *str, size_t len, t_error *error);
void	count_ex_col_pos(t_data *data, t_error *error);
void	verif_ex_col_pos(t_error *error);
void	parsing_msg_error(t_error *error);

#endif
