#include "so_long"

void    move_up(t_game *game) // we need to get the py & px first
{
    //check if next move is not a wall, game->map[game->px -1][game->px] != '1'
    //inside check if next move is collectable if yes call a function
    // else check if next move is an exit && game->collect = 0 if yes call exit_game
    //else move accordingly
    // for example game->py--
    //and count moves/steps and print them
    // if i need space make new function that move player 
    // dont forget to call img on win function to update
}

void    move_down(t_game *game)
{}

void    move_right(t_game *game)
{}

void    move_left(t_game *game)
{}
