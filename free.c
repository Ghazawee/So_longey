#include "so_long.h"

void    destroy_imgs(t_game *game)
{
    if(game->wimg)
        mlx_destroy_image(game->mlx_ptr, game->wimg);
    if(game->pimg)
       mlx_destroy_image(game->mlx_ptr, game->pimg);
    if(game->fimg)
        mlx_destroy_image(game->mlx_ptr, game->fimg);
    if(game->cimg)
        mlx_destroy_image(game->mlx_ptr, game->cimg);
    if(game->eimg)
        mlx_destroy_image(game->mlx_ptr, game->eimg);
}

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
    if (game->mlx_win)
        mlx_destroy_window(game->mlx_ptr, game->mlx_win);
}

int    x_mark_clicked(t_game *game)
{
    exit_game_esc_x(game);
    return (0);
}