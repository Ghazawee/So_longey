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
    int     steps;
    int     score;
    int     toscore;
    int     gover;
    int     x;
    int     y;
    void    *fimg;
    void    *pimg;
    void    *wimg;
    void    *eimg;
    void    *cimg;
}t_game;



#endif