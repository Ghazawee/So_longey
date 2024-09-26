/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:37:07 by mshaheen          #+#    #+#             */
/*   Updated: 2024/09/26 18:06:05 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "mlx/mlx.h"
#include "get_next_line/get_next_line.h"
//#include "MinilibX/mlx.h"

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

//free
int check_ber(char *str);
void    destroy_imgs(t_game *game);
void    free_map_array(t_game *game);
int    x_mark_clicked(t_game *game);

//handle_events
int    key_pressed(int key, t_game *game);
void    is_it_collectiible(t_game *game);
void    is_exit_open(t_game *game);
void    exit_game_esc_x(t_game *game);
void    exit_game_done(t_game *game);

//move_player
void    get_px_py(t_game *game);
void    move_upwards(t_game *game);
void    move_downwards(t_game *game);
void    move_to_right(t_game *game);
void    move_to_left(t_game *game);

//map_utils
int     rows_count(char *map, t_game *game);
void    put_imgs(t_game *game);
void    img_on_win(t_game *game, int ts);

//map_parse
void    map_parsing(t_game *game);

//str_utils
int	fts_strlen(char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void    print_map(t_game *game);

#endif