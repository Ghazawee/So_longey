/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:36:58 by mshaheen          #+#    #+#             */
/*   Updated: 2024/09/30 20:05:43 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_val(t_game *game)
{
	game->mlx_ptr = NULL;
	game->mlx_ptr = NULL;
	game->map = NULL;
	game->player = 0;
	game->collect = 0;
	game->exit = 0;
	game->steps = 0;
	game->ex = 0;
	game->ey = 0;
	game->rows = 0;
	game->columns = 0;
	game->px = 0;
	game->py = 0;
	game->fimg = NULL;
	game->pimg = NULL;
	game->wimg = NULL;
	game->eimg = NULL;
	game->cimg = NULL;
}

void	read_map(char *map, t_game *game)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
		exit(1);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		free_map_array(game);
		write(2, "Map not found\n", 14);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		game->map[rows] = line;
		rows++;
		line = get_next_line(fd);
	}
	game->map[rows] = NULL;
	close(fd);
}

void	check_res(int columns, int rows)
{
	if (columns > 40 || rows > 21)
	{
		write(2, "Map too big\n", 12);
		exit(1);
	}
	return ;
}

void	begin_game(char *map, t_game *game)
{
	game->rows = rows_count(map, game);
	check_res(game->columns, game->rows);
	read_map(map, game);
	map_parsing(game);
	get_px_py(game);
	get_ex_ey(game);
	bfs(game);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit(1);
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->columns * 64, game->rows
			* 64, "so_long");
	if (!game->mlx_win)
	{
		free(game->mlx_ptr);
		exit(1);
	}
	put_imgs(game);
	img_on_win(game, 64);
	// mlx_key_hook(game->mlx_win, key_pressed, game);
	mlx_hook(game->mlx_win, 2, 0, key_pressed, game);
	mlx_hook(game->mlx_win, 17, 0, x_mark_clicked, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		write(2, "Only one argument should be passed\n", 35);
		exit(1);
	}
	if (check_ber(av[1]) == 0)
	{
		write(2, "Invalid Map\n", 12);
		exit(1);
	}
	init_val(&game);
	begin_game(av[1], &game);
}
