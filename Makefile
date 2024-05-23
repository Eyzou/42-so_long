NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
#MLX = -Lmlx -lmlx -L/usr/lib -lXext -lX11
ARCH_FLAGS = -arch arm64
MLXMAC = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
LIB_FLAGS = -Llibft -lft

#INCLUDE = -I ./includes -I ./libft -I ./mlx
INCLUDE = -I ./includes -I ./libft -I ./mlx -I/opt/X11/include
SRCS = srcs/main.c \
		srcs/init.c \
		srcs/graphics.c \
		srcs/hook.c \
		srcs/move.c \
		srcs/check_map.c \
		srcs/check_map2.c \
		srcs/close.c \
		srcs/define.c \
		srcs/display.c \
		srcs/enemy.c\
		srcs/animations.c

SRCS_BONUS = srcs/main.c \
			srcs/init.c \
			srcs/graphics.c \
			srcs/hook.c \
			srcs/move.c \
			srcs/check_map.c \
			srcs/check_map2.c \
			srcs/close.c \
			srcs/define.c \
			srcs/display.c \
			srcs/enemy.c\
			srcs/animations.c 
		
OBJ =			$(SRCS:%.c=%.o)
OBJ_BONUS = 	$(SRCS_B:%.c=%.o)

all: ${NAME}

bonus: ${NAME_BONUS}

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -O2 -c $< -o $(<:%.c=%.o)

$(NAME): $(OBJ)
	make -C ./mlx
	make all -C ./libft
#	$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAGS) $(MLX) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAGS) $(ARCH_FLAGS) $(MLXMAC) -o $(NAME)

${NAME_BONUS}: $(OBJ_BONUS)
	make -C ./mlx
	make all -C ./libft
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB_FLAGS) $(ARCH_FLAGS) $(MLXMAC) -o $(NAME_BONUS)


clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
	make clean -C ./libft 

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C ./libft 
	
re:	fclean all

.PHONY: all clean fclean re
