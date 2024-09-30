/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:03:31 by mshaheen          #+#    #+#             */
/*   Updated: 2024/09/30 21:03:31 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i -= 4;
	if (ft_strncmp(&str[i], ".ber", 4) != 0)
		return (0);
	return (1);
}

void	destroy_imgs(t_game *game)
{
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
}

void	free_map_array(t_game *game)
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
}

void	free_all(t_game *game)
{
	destroy_imgs(game);
	free_map_array(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	free(game->mlx_ptr);
}

int	x_mark_clicked(t_game *game)
{
	exit_game_esc_x(game);
	exit(0);
}
