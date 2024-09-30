/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:44:27 by mshaheen          #+#    #+#             */
/*   Updated: 2024/09/30 20:07:46 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_px_py(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->py = i;
				game->px = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	move_upwards(t_game *game)
{
	get_px_py(game);
	if (game->map[game->py - 1][game->px] != '1')
	{
		game->map[game->py][game->px] = '0';
		if (game->map[game->py - 1][game->px] == 'C')
			is_it_collectiible(game, game->px, game->py - 1);
		else if (game->map[game->py - 1][game->px] == 'E')
			is_exit_open(game);
		else
		{
			game->py--;
			game->steps++;
			ft_printf("steps: %d\n", game->steps);
			game->map[game->py][game->px] = 'P';
			img_on_win(game, 64);
		}
	}
}

void	move_downwards(t_game *game)
{
	get_px_py(game);
	if (game->map[game->py + 1][game->px] != '1')
	{
		game->map[game->py][game->px] = '0';
		if (game->map[game->py + 1][game->px] == 'C')
			is_it_collectiible(game, game->px, game->py + 1);
		else if (game->map[game->py + 1][game->px] == 'E')
			is_exit_open(game);
		else
		{
			game->py++;
			game->steps++;
			ft_printf("steps: %d\n", game->steps);
			game->map[game->py][game->px] = 'P';
			img_on_win(game, 64);
		}
	}
}

void	move_to_right(t_game *game)
{
	get_px_py(game);
	if (game->map[game->py][game->px + 1] != '1')
	{
		game->map[game->py][game->px] = '0';
		if (game->map[game->py][game->px + 1] == 'C')
			is_it_collectiible(game, game->px + 1, game->py);
		else if (game->map[game->py][game->px + 1] == 'E')
			is_exit_open(game);
		else
		{
			game->px++;
			game->steps++;
			ft_printf("steps: %d\n", game->steps);
			game->map[game->py][game->px] = 'P';
			img_on_win(game, 64);
		}
	}
}

void	move_to_left(t_game *game)
{
	get_px_py(game);
	if (game->map[game->py][game->px - 1] != '1')
	{
		game->map[game->py][game->px] = '0';
		if (game->map[game->py][game->px - 1] == 'C')
			is_it_collectiible(game, game->px - 1, game->py);
		else if (game->map[game->py][game->px - 1] == 'E')
			is_exit_open(game);
		else
		{
			game->px--;
			game->steps++;
			ft_printf("steps: %d\n", game->steps);
			game->map[game->py][game->px] = 'P';
			img_on_win(game, 64);
		}
	}
}
