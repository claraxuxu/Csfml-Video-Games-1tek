/*
** EPITECH PROJECT, 2020
** my_window_game
** File description:
** the result
*/

#include "runner.h"

void game_ended_colision(struct game *game)
{
    stop_music(game);
    game->step = 2;
    sfText_setString(game->gui->texts->game_over,
                     get_sentence(game->won));
}

void game_won(struct game *game)
{
    stop_music(game);
    game->won = 1;
    sfText_setString(game->gui->texts->game_over,
                     get_sentence(game->won));
    game->step = 2;
}
