/*
** EPITECH PROJECT, 2020
** my_window_mouse_pressed
** File description:
** deal with mouse events
*/

#include "runner.h"

void mouse_pressed_start(struct game *game, const sfVector2f mouse)
{
    const int size = 256;

    if (window_contain_point(game->gui->sprites->select, mouse, size) == 1) {
        list_maps(game);
        game->step = 4;
    }
    if (window_contain_point(game->gui->sprites->play, mouse, size) == 1) {
        sfSprite_setPosition(game->player->sprite, get_position(170, 674));
        free_all_obstacles(game);
        game->score = 0;
        game->step = 1;
        play_random_music(game);
    }
}
void mouse_pressed_maps(struct game *game, const sfVector2f mouse)
{
    const int b_size = 72;

    if (window_contain_point(game->gui->sprites->back, mouse, b_size) == 1)
        game->step = 0;
    for (int i = 0; i < game->maps_len; i++)
        if (window_contain_map(game->gui->texts->maps_fields[i], mouse))
            map_selected(game, i);
}

void mouse_pressed_end(struct game *game, const sfVector2f mouse)
{
    const int size = 256;

    game->won = 0;
    if (window_contain_point(game->gui->sprites->play, mouse, size) == 1) {
        free_all_obstacles(game);
        game->score = 0;
        sfText_setString(game->gui->texts->score, my_itc(game->score));
        game->step = 1;
        play_random_music(game);
        if (game->options->custom == 1)
            parse_map(game);
    }
    if (window_contain_point(game->gui->sprites->menu, mouse, size) == 1) {
        free_all_obstacles(game);
        game->score = 0;
        game->step = 0;
        game->options->custom = 0;
    }
}

void mouse_pressed_break(struct game *game, const sfVector2f mouse)
{
    const int b_size = 72;
    const int size = 256;

    if (window_contain_point(game->gui->sprites->back, mouse, b_size) == 1)
        game->step = 1;
    if (window_contain_point(game->gui->sprites->play, mouse, size) == 1) {
        free_all_obstacles(game);
        game->score = 0;
        sfText_setString(game->gui->texts->score, my_itc(game->score));
        game->step = 1;
        play_random_music(game);
        if (game->options->custom == 1)
            parse_map(game);
    }
    mouse_pressed_break_ext(game, mouse);
}
