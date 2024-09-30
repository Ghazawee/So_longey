/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:38:23 by mshaheen          #+#    #+#             */
/*   Updated: 2024/09/30 20:36:32 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game_esc_x(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (game->wimg)
		mlx_destroy_image(game->mlx_ptr, game->wimg);
	if (game->pimg)
		mlx_destroy_image(game->mlx_ptr, game->pimg);
	if (game->fimg)
		mlx_destroy_image(game->mlx_ptr, game->fimg);
	if (game->cimg)
		mlx_destroy_image(game->mlx_ptr, game->cimg);
	if (game->eimg)
		mlx_destroy_image(game->mlx_ptr, game->eimg);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
}

int	key_pressed(int key, t_game *game)
{
	if (key == 53)
	{
		exit_game_esc_x(game);
		exit(0);
	}
	else if (key == 13)
	{
		move_upwards(game);
	}
	else if (key == 1)
	{
		move_downwards(game);
	}
	else if (key == 0)
	{
		move_to_left(game);
	}
	else if (key == 2)
	{
		move_to_right(game);
	}
	return (0);
}

void	is_it_collectiible(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->collect--;
	}
	game->steps++;
	game->map[y][x] = 'P';
	ft_printf("steps: %d\n", game->steps);
	img_on_win(game, 64);
}

void	exit_game_done(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_image(game->mlx_ptr, game->wimg);
	mlx_destroy_image(game->mlx_ptr, game->pimg);
	mlx_destroy_image(game->mlx_ptr, game->fimg);
	mlx_destroy_image(game->mlx_ptr, game->cimg);
	mlx_destroy_image(game->mlx_ptr, game->eimg);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	free(game->mlx_ptr);
	write(1, "Congrats!!, You WON\n", 20);
	exit(0);
}

void	is_exit_open(t_game *game)
{
	if (game->collect == 0)
	{
		game->steps++;
		ft_printf("steps: %d\n", game->steps);
		exit_game_done(game);
	}
}
