NAME = so_long


MLX_DIR = mlx
GNL_DIR = get_next_line
FPF = ft_printf
IMG_DIR = imgs

SRCS = so_long.c \
       move_player.c \
       map_utils.c \
       map_parse.c \
       handle_events.c \
       bfs.c free.c \
	   str_utils.c \
       $(GNL_DIR)/get_next_line.c \
       $(GNL_DIR)/get_next_line_utils.c\
	   $(FPF)/ft_printf.c $(FPF)/dicases.c\
	   $(FPF)/ft_putchar.c $(FPF)/ft_puthbr.c\
	   $(FPF)/ft_putnbr.c $(FPF)/ft_putpbr.c\
	   $(FPF)/ft_putstr.c $(FPF)/ft_putubr.c\

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

IMGS = $(IMG_DIR)/walls.xpm $(IMG_DIR)/player.xpm $(IMG_DIR)/floor.xpm $(IMG_DIR)/exit.xpm $(IMG_DIR)/collet.xpm


all: $(NAME)


$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean 

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean 

re: fclean all

.PHONY: all clean fclean re