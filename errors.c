/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:22:59 by mshaheen          #+#    #+#             */
/*   Updated: 2024/10/01 11:00:38 by mshaheen         ###   ########.fr       */
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


void free_visited(t_bfs *cir, int rows)
{
	int j;

	j = 0;
	while (j < rows)
		free(cir->visited[j++]);
	free(cir->visited);
}

void	ft_malloc_protect(t_bfs *cir, t_game *game, int i)
{
	cir->queue = malloc(sizeof(t_axis) * ((game->columns * game->rows)));
	if (!cir->queue)
	{
		free_map_array(game);
		write(2, "Error in malloc\n", 16);
		exit(1);
	}
	cir->visited = malloc(sizeof(int *) * (game->rows));
	if (!cir->visited)
	{
		free_map_array(game);
		free(cir->queue);
		write(2, "Error in malloc\n", 16);
		exit(1);
	}
}
	
void	ft_calloc_protect(t_bfs *cir, t_game *game, int i)
{
	while (i < game->rows)
	{
		cir->visited[i] = fts_calloc((size_t)(game->columns), sizeof(int));
		if (!cir->visited[i])
		{
			free_visited(cir, i);
			free(cir->queue);
			free_map_array(game);
			write(2, "Error in malloc visited\n", 24);
			exit(1);
		}
		i++
	}
}