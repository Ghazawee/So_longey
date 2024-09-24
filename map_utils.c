#include "so_long.h"


int rows_count(char *map)
{
    int fd;
    int rows;
    char *line;

    fd = open(map, O_RDONLY);
    if(!fd)
    {
        write(2, "Error opening map\n", 18);
        exit(1);
    }
    line = get_next_line(fd);
    while (line)
    {
        rows++;
        free(line);
        line = get_next_line(fd);
    }
    return (rows)
}

void    put_imgs(t_game *game)
{
    int w;
    int h;

    game->wimg = mlx_xpm_file_to_image(game->mlx_ptr, "path for wall img", &w, &h);
    game->pimg = mlx_xpm_file_to_image(game->mlx_ptr, "path for player img", &w, &h);
    game->fimg = mlx_xpm_file_to_image(game->mlx_ptr, "path for floor img", &w, &h);
    game->cimg = mlx_xpm_file_to_image(game->mlx_ptr, "path for collectable img", &w, &h);
    game->eimg = mlx_xpm_file_to_image(game->mlx_ptr, "path for exit img", &w, &h);

    if (!game->wimg || !game->pimg || !game->fimg || !game->cimg || !game->eimg)
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
        free_map_array(game);
        write(2, "Error loading image\n", 20);
        exit(1);
    }
}

void    img_on_win(t_game *game, int ts) // rendering
{
    int r;
    int c;

    r = 0;
    while(game->map[r])
    {
        c = 0;
        while(game->map[r][c])
        {
            if(game->map[r][c] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->wimg, r * ts, c * ts);
            else if(game->map[r][c] == 'P')
                mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->pimg, r * ts, c * ts);
            else if(game->map[r][c] == '0')
                mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->fimg, r * ts, c * ts);
            else if(game->map[r][c] == 'C')
                mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->cimg, r * ts, c * ts);
            else if(game->map[r][c] == 'E')
                mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->eimg, r * ts, c * ts);
            c++;
        }
        r++;
    }
}

void print_map(t_game *game) // just to see if the map is read correctly
{
    int i= 0;
    while (game->map[i])
    {
        write(1, game->map[i], ft_strlen(game->map[i]));
        write(1, "\n", 1);
        i++;
    }
}