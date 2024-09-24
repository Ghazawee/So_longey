#ifndef SO_LONG_H
#define SO_LONG_H
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "MinilibX/mlx.h"

typedef struct s_game{

    void    *mlx_ptr;
    void    *mlx_win;
    char    **map;
    int     player;
    int     collect;
    int     exit;
    int     steps;
    int     score;
    int     toscore;
    int     gover;
    int     px;
    int     py;
    void    *fimg;
    void    *pimg;
    void    *wimg;
    void    *eimg;
    void    *cimg;
}t_game;

void    destroy_imgs(t_game *game);
void    free_map_array(t_game *game);
int    x_mark_clicked(t_game *game);

void    key_pressed(int key, t_game *game);
void    is_it_collectiible(t_game *game);
void    is_exit_open(t_game *game);
void    exit_game_x(t_game *game);
void    exit_game_done(t_game *game);

void    move_up(t_game *game);
void    move_down(t_game *game);
void    move_right(t_game *game);
void    move_left(t_game *game);


int     rows_count(char *map);
void    put_imgs(t_game *game);
void    img_on_win(t_game *game, int ts);
void    map_parsing(t_game *game);

#endif