/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:40:12 by mshaheen          #+#    #+#             */
/*   Updated: 2024/09/30 20:45:14 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		is_valid_path(t_game *game, t_bfs *cir, int x, int y);
void	enqueue(t_bfs *cir, int x, int y);
void	process_pos(t_game *game, t_bfs *cir, t_axis curr);
void	freevq(t_bfs *cir, t_game *game);



void	bfs(t_game *game)
{
	t_bfs	cir;
	int		i;
	t_axis	curr;

	ft_malloc_protect(&cir, game);
	cir.rear = 0;
	cir.front = 0;
	i = 0;
	ft_calloc_protect(&cir, game, i);
	cir.checkc = game->collect;
	enqueue(&cir, game->px, game->py);
	while (cir.front < cir.rear)
	{
		curr = cir.queue[cir.front++];
		process_pos(game, &cir, curr);
	}
	if (cir.checkc != 0 || !cir.visited[game->ey][game->ex])
	{
		free_all(game);
		freevq(&cir, game);
		ft_error(3);
	}
	freevq(&cir, game);
}

int	is_valid_path(t_game *game, t_bfs *cir, int x, int y)
{
	if (x < 0 || x >= game->columns || y < 0 || y >= game->rows)
		return (0);
	if (game->map[y][x] == 'E' && cir->checkc > 0)
	{
		cir->visited[y][x] = 1;
		return (0);
	}
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

void	enqueue(t_bfs *cir, int x, int y)
{
	cir->queue[cir->rear].x = x;
	cir->queue[cir->rear++].y = y;
	cir->visited[y][x] = 1;
}

void	process_pos(t_game *game, t_bfs *cir, t_axis curr)
{
	int	x;
	int	y;

	x = curr.x;
	y = curr.y;
	if (game->map[y][x] == 'C')
		cir->checkc--;
	if (is_valid_path(game, cir, x, y - 1) && !cir->visited[y - 1][x])
		enqueue(cir, x, y - 1);
	if (is_valid_path(game, cir, x, y + 1) && !cir->visited[y + 1][x])
		enqueue(cir, x, y + 1);
	if (is_valid_path(game, cir, x - 1, y) && !cir->visited[y][x - 1])
		enqueue(cir, x - 1, y);
	if (is_valid_path(game, cir, x + 1, y) && !cir->visited[y][x + 1])
		enqueue(cir, x + 1, y);
}


void	freevq(t_bfs *cir, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
		free(cir->visited[i++]);
	free(cir->visited);
	free(cir->queue);
}
