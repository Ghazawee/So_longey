/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:36:58 by mshaheen          #+#    #+#             */
/*   Updated: 2024/09/26 18:45:05 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"


void    init_val(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
        exit(1);
    game->mlx_win = mlx_new_window(game->mlx_ptr, 800, 640, "so_long");
    if (!game->mlx_win)
    {
        free(game->mlx_ptr);
        exit(1);
    }
    game->map = NULL;
    game->player = 0;
    game->collect = 0;
    game->exit = 0;
    game->steps = 0;
    game->score = 0;
    game->toscore = 0;
    game->gover = 0;
    game->px = 0;
    game->py = 0;
    game->fimg = NULL;
    game->pimg = NULL;
    game->wimg = NULL;
    game->eimg = NULL;
    game->cimg = NULL;
}
void    read_map(char *map, t_game *game)
{
    int fd;
    int rows;
    int total_rows;
    char    *line;

    rows = 0;
    total_rows = rows_count(map, game);
    game->map = (char **)malloc(sizeof(char *) * total_rows + 1);
    if (!game->map)
        exit(1);
    fd = open(map, O_RDONLY);
    if (fd == -1)
    {
        free(game->map);
        write(2, "Map not found\n", 14);
        exit(1);
    }
    line = get_next_line(fd); // i think i have to free but i need to do some strdup strjoin stuff
    while(line)
    {
        game->map[rows] = line;
        rows++;
        line = get_next_line(fd);
    }
    game->map[rows] = NULL;
    close(fd);
    //print_map(game); // dont need this
}
void    begin_game(char *map, t_game *game)
{
    read_map(map, game);
    //print_map(game);
    map_parsing(game);
    bfs(game);
    put_imgs(game);
    img_on_win(game, 32);
    mlx_key_hook(game->mlx_win, key_pressed, game);
    mlx_hook(game->mlx_win, 17, 1L<<17, x_mark_clicked, game);
    mlx_loop(game->mlx_ptr);
    // i can add a function that checks if the map has been read properly
    //render the map and images
    //key handles
    //player movements
}

int main(int ac, char **av)
{
    t_game  game;

    if (ac != 2)
    {
        write(2, "Only one argument should be passed\n", 35);
        exit(1);
    }
    //check if av[1] || map ends in .ber else exit(1) with error
    if(check_ber(av[1]) == 0)
    {
        write(2, "Invalid Map\n", 12);
        exit(1);
    }
    init_val(&game);
    begin_game(av[1], &game);
     //mlx_hook(game.mlx_win, 17, 1L<<17, x_mark_clicked, &game);
    // mlx_loop(game.mlx_ptr);
}

