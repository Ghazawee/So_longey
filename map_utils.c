/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:59:40 by mshaheen          #+#    #+#             */
/*   Updated: 2024/09/30 20:59:40 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rows_count(char *map, t_game *game)
{
	char	*line;
	int		fd;
	int		rows;
	int		columns;

	rows = 0;
	columns = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error(1);
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		columns = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	game->columns = columns;
	game->rows = rows;
	if (game->rows == 0 && game->columns == 0)
		ft_error(2);
	return (rows);
}

void	put_imgs(t_game *game)
{
	int	w;
	int	h;

	game->wimg = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/wall_64.xpm", &w,
			&h);
	game->pimg = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/player2_64.xpm", &w,
			&h);
	game->fimg = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/floor_64.xpm", &w,
			&h);
	game->cimg = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/collect_64.xpm", &w,
			&h);
	game->eimg = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/exit_64.xpm", &w,
			&h);
	if (!game->wimg || !game->pimg || !game->fimg || !game->cimg
		|| !game->eimg)
	{
		free_all(game);
		write(2, "Error loading image\n", 20);
		exit(1);
	}
}

void	img_on_win(t_game *game, int ts)
{
	int	r;
	int	c;

	r = 0;
	while (game->map[r])
	{
		c = 0;
		while (game->map[r][c])
		{
			img_to_win_assist(game, r, c, ts);
			c++;
		}
		r++;
	}
}

void	get_ex_ey(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				game->ey = i;
				game->ex = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		write(1, game->map[i], ft_strlen(game->map[i]));
		i++;
	}
	write(1, "\n", 1);
}
