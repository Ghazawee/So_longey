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