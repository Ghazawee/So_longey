#include "so_long.h"

void    free_map_array(t_game *game)
{
    int i;

    i = 0;
    if (game->map)
    {
        while(game->map[i])
        {
            free(game->map[i]);
            i++;
        }
        free(game->map);
    }
}