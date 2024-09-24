#include "so_long.h"

void    key_pressed(int key, t_game *game)
{
    //if key = esc // exit
    //else if key = W // function to move up
    //else if key = S // function to move down and so on
}

void    is_it_collectiible(t_game *game);

void    is_exit_open(t_game *game);

void    exit_game_x(t_game *game)
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
    if (game->mlx_win)
        mlx_destroy_window(game->mlx_ptr, game->mlx_win);
}

void    exit_game_done(t_game *game)
{
    int i;

    i = 0;
    while(game->map[i])
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
    exit(0);
}