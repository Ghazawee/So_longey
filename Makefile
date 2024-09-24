NAME = so_long

MLX = ../MinilibX/mlx.h
MLX_FLAGS = 

SRC = so_long.c parse.c free.c

OBJ = $(SRC:.c=.o)

CC = CC

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)