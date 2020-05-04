/*
** EPITECH PROJECT, 2020
** my_window_music
** File description:
** play or stop musics
*/

#include "runner.h"

void play_random_music(struct game *game)
{
    char music_path[28] = "resources/music_1.ogg";

    game->music = sfMusic_createFromFile(music_path);
    sfMusic_play(game->music);
}

void play_music(struct game *game)
{
    if (game->music == NULL) {
        play_random_music(game);
        return;
    }
    sfMusic_play(game->music);
}

void stop_music(struct game *game)
{
    if (game->music == NULL)
        return;
    sfMusic_destroy(game->music);
}
