/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:44:27 by mshaheen          #+#    #+#             */
/*   Updated: 2024/09/29 18:12:46 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_px_py(t_game *game)
{
    int i;
    int j;

    i = 0;
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if(game->map[i][j] == 'P')
            {
                game->py = i;
                game->px = j;
                break;
            }
            j++;
        }
        i++;
    }
}

void    move_upwards(t_game *game) // we need to get the py & px first
{
    get_px_py(game);
    if (game->map[game->py - 1][game->px] != '1')
    {
        game->map[game->py][game->px] = '0';
        if (game->map[game->py - 1][game->px] == 'C')
            is_it_collectiible(game, game->px, game->py - 1);
            //game->collect--;
            //is_it_collectiible(game);
        else if (game->map[game->py - 1][game->px] == 'E')
            is_exit_open(game);
        else
        {
            game->py--;
            game->steps++;
            //printf("steps: %d\n", game->steps);
            ft_printf("steps: %d\n", game->steps);
            // set new pos here before calling function ?? // game->map[game->py][game->px] = 'P';
            game->map[game->py][game->px] = 'P';
            img_on_win(game, 64);
        }  
    }
    //check if next move is not a wall, game->map[game->px -1][game->px] != '1'
    //inside check if next move is collectable if yes call a function
    // else check if next move is an exit && game->collect = 0 if yes call exit_game
    //else move accordingly
    // for example game->py--
    //and count moves/steps and print them
    // if i need space make new function that move player 
    // dont forget to call img on win function to update
}

void    move_downwards(t_game *game)
{
    get_px_py(game);
    if (game->map[game->py + 1][game->px] != '1')
    {
        game->map[game->py][game->px] = '0';
        if (game->map[game->py + 1][game->px] == 'C')
            is_it_collectiible(game, game->px, game->py + 1);
            //game->collect--;
        else if (game->map[game->py + 1][game->px] == 'E')
            is_exit_open(game);
        else
        {
            game->py++;
            game->steps++;
            ft_printf("steps: %d\n", game->steps);
            //printf("steps: %d\n", game->steps);
            //similar to upw
            game->map[game->py][game->px] = 'P';
            img_on_win(game, 64);
        }  
    }
}

void    move_to_right(t_game *game)
{
    get_px_py(game);
    if (game->map[game->py][game->px + 1] != '1')
    {
        game->map[game->py][game->px] = '0';
        if (game->map[game->py][game->px + 1] == 'C')
            is_it_collectiible(game, game->px + 1, game->py);
            //game->collect--;
        else if (game->map[game->py][game->px + 1] == 'E')
            is_exit_open(game);
        else
        {
            game->px++;
            game->steps++;
            ft_printf("steps: %d\n", game->steps);
            //printf("steps: %d\n", game->steps);
            //similar to upw
            game->map[game->py][game->px] = 'P';
            img_on_win(game, 64);
        }  
    }
}

void    move_to_left(t_game *game)
{
    get_px_py(game);
    if (game->map[game->py][game->px - 1] != '1')
    {
        game->map[game->py][game->px] = '0';
        if (game->map[game->py][game->px - 1] == 'C')
            is_it_collectiible(game, game->px - 1, game->py);
            //game->collect--;
        else if (game->map[game->py][game->px - 1] == 'E')
            is_exit_open(game);
        else
        {
            game->px--;
            game->steps++;
            ft_printf("steps: %d\n", game->steps);
            //printf("steps: %d\n", game->steps);
            //similar to upw
            game->map[game->py][game->px] = 'P';
            img_on_win(game, 64);
        }  
    }
}

