CC				= gcc 
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g3	-I./includes -I./mlx_linux
MLX 			= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME 	= so_long
SRCS	= ./srcs/game/so_long.c ./srcs/game/moves.c ./srcs/gnl/get_next_line.c ./srcs/gnl/utils/get_next_line_utils.c \
			./srcs/parsing/parsing_map.c  ./srcs/parsing/parsing_file.c ./srcs/parsing/parsing_valid_path.c \
			./srcs/utils/parsing_utils.c ./srcs/utils/game_init.c ./srcs/utils/game_utils.c ./srcs/utils/free_utils.c\
			./srcs/utils/print_utils.c \

OBJS 	= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):	$(OBJS)
			make -C ./mlx_linux
			$(CC) -o $(NAME) $(SRCS) $(CFLAGS) $(MLX)

clean:
				$(RM) $(OBJS)
				 
fclean:	 		clean
				make  clean -C ./mlx_linux
				$(RM) $(NAME)

	
re:				fclean all

.PHONY:			all clean fclean re