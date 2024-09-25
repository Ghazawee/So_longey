NAME = so_long

MLX = ../mlx/mlx.h
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC = so_long.c map_parse.c free.c handle_events.c\
	map_utils.c move_player.c str_utils.c

OBJ = $(SRC:.c=.o)

CC = CC

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJ)

