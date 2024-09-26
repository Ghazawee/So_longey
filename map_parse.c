/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:38:05 by mshaheen          #+#    #+#             */
/*   Updated: 2024/09/26 16:21:54 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *rem_newline(char *str)
{
    int len = fts_strlen(str);
   if(len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
    return(str);
}

int map_rect(t_game *game)
{
    int i;
    int rlen;

    i = 1;
    rlen = fts_strlen(rem_newline(game->map[0]));
    while(game->map[i])
    {
        if ((fts_strlen(rem_newline(game->map[i]))) != rlen)
            return (0);
        i++;
    }
    return (1);
}

int valid_map(t_game *game)
{
    int i;
    int j;
    
    i = 0;
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if (game->map[i][j] == 'P')
                game->player++;
            else if (game->map[i][j] == 'C')
                game->collect++;
            else if (game->map[i][j] == 'E')
                game->exit++;
            else if(game->map[i][j] != '1' && game->map[i][j] != '0')
                return (0);
            j++;
        }
        i++;
    }
    if (game->player != 1 || game->collect < 1 || game->exit != 1)
        return (0);
    return (1);
}

int surr_walls(t_game *game)
{
    int i;
    int rowend;
    int rlen;

    i = 0;
    rowend = 0;
    rlen = ft_strlen(game->map[0]);
    while(game->map[rowend])
        rowend++;
    rowend--;
    while (i < rlen)
    {
        if (game->map[0][i] != '1' || game->map[rowend][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i <= rowend)
    {
        if (game->map[i][0] != '1' || game->map[i][rlen -1] != '1')
            return (0);
        i++;
    }
    return (1);
}

void    map_parsing(t_game *game)
{
    if (!map_rect(game))
    {
        write(2, "Map is not rectangular\n", 23);
        free_map_array(game);
        exit(1);
    }
    if (!valid_map(game))
    {
        printf("player: %d, collect: %d, exit: %d\n", game->player, game->collect, game->exit);
        write(2, "Required Characters not found\n", 30);
        free_map_array(game);
        exit(1);
    }
    if (!surr_walls(game))
    {
        write(2, "Map not surrounded by walls\n", 28);
        free_map_array(game);
        exit(1);
    }
}
