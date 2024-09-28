#include "so_long.h"

int is_valid_path(t_game *game, int x, int y);
void    enqueue(t_bfs *cir, int x, int y);
void    process_pos(t_game  *game, t_bfs *cir, t_axis curr);
void    freevq(t_bfs *cir, t_game *game);

void bfs(t_game *game)
{
    t_bfs   cir;
    int     i;
    t_axis  curr;

    cir.queue = malloc(sizeof(t_axis) * game->columns * game->rows);
    cir.rear = 0;
    cir.front = 0;
    enqueue(&cir, game->px, game->py);
    cir.visited = malloc(sizeof(int *) * game->rows);
    i = 0;
    while(i < game->rows)
        cir.visited[i++] = ft_calloc((size_t)game->columns, sizeof(int));
    cir.checkc = game->collect;
    while(cir.front < cir.rear)
    {
        curr = cir.queue[cir.front++];
        process_pos(game, &cir, curr);
    }
    if (cir.checkc != 0 || !cir.visited[game->ey][game->ex])
    {
        free_all(game);
        freevq(&cir, game);
        write(2, "Unreachable collectable or exit\n", 32);
        exit(1);
    }
    freevq(&cir, game);
}

int is_valid_path(t_game *game, int x, int y)
{
    if (x < 0 || x >= game->columns || y < 0 || y >= game->rows)
        return (0);
    if (game->map[y][x] == '1' || (game->map[y][x] == 'E' && game->collect > 0))
        return (0);
    return (1);
}
void enqueue(t_bfs *cir, int x, int y)
{
    cir->queue[cir->rear].x = x;
    cir->queue[cir->rear++].y = y;
    cir->visited[y][x] = 1;
}

void process_pos(t_game  *game, t_bfs *cir, t_axis curr)
{
    int x;
    int y;

    x = curr.x;
    y = curr.y;
    if (game->map[y][x] == 'C')
        cir->checkc--;
    if(is_valid_path(game, x, y - 1) && !cir->visited[y - 1][x])
        enqueue(cir, x, y - 1);
    if(is_valid_path(game, x, y + 1) && !cir->visited[y + 1][x])
        enqueue(cir, x, y + 1);
    if(is_valid_path(game, x - 1, y) && !cir->visited[y][x - 1])
        enqueue(cir, x - 1,y);
    if(is_valid_path(game, x + 1, y) && !cir->visited[y][x + 1])
        enqueue(cir, x + 1, y);
}

void    freevq(t_bfs *cir, t_game *game)
{
    int i;

    i = 0;
    while(i < game->rows)
        free(cir->visited[i++]);
    free(cir->visited);
    free(cir->queue);
}