/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:22:59 by mshaheen          #+#    #+#             */
/*   Updated: 2024/09/30 20:45:36 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int i)
{
	if (i == 1)
	{
		write(2, "Map not found\n", 14);
		exit(1);
	}
	else if (i == 2)
	{
		write(2, "Inavlid Map, Map is empty\n", 26);
		exit(1);
	}
	else if (i == 3)
	{
		write(2, "Unreachable collectable or exit\n", 32);
		exit(1);
	}
}

void	img_to_win_assist(t_game *game, int r, int c, int ts)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->fimg, c * ts, r
		* ts);
	if (game->map[r][c] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->wimg, c
			* ts, r * ts);
	else if (game->map[r][c] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->pimg, c
			* ts, r * ts);
	else if (game->map[r][c] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->fimg, c
			* ts, r * ts);
	else if (game->map[r][c] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->cimg, c
			* ts, r * ts);
	else if (game->map[r][c] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->eimg, c
			* ts, r * ts);
}
