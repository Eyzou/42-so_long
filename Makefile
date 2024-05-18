NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
#MLX = -Lmlx -lmlx -L/usr/lib -lXext -lX11
ARCH_FLAGS = -arch arm64
MLXMAC = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
LIB_FLAGS = -Llibft -lft

#INCLUDE = -I ./includes -I ./libft -I ./mlx
INCLUDE = -I ./includes -I ./libft -I ./mlx -I/opt/X11/include
SRCS = srcs/main.c \
		srcs/graphics.c \
		srcs/settings.c \
		srcs/hook.c \
		srcs/move.c \
		srcs/check_map.c \
		srcs/close.c \
		srcs/define.c \
		srcs/utils.c

OBJ = $(SRCS:%.c=%.o)

all: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -O2 -c $< -o $(<:%.c=%.o)

$(NAME): $(OBJ)
	make -C ./mlx
	make all -C ./libft
#	$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAGS) $(MLX) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAGS) $(ARCH_FLAGS) $(MLXMAC) -o $(NAME)


clean:
	rm -rf $(OBJ)
	rm -rf /a.out
	make clean -C ./libft 

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft 
	
re:	fclean all

.PHONY: all clean fclean re
