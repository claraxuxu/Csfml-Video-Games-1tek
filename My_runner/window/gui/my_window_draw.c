/*
** EPITECH PROJECT, 2020
** my_window_draw
** File description:
** give images
*/

#include "runner.h"

void window_draw(struct game *game)
{
    sfRenderWindow_clear(game->gui->window, sfBlack);
    if (game->step == 0)
        window_draw_start(game);
    if (game->step == 1)
        window_draw_game(game);
    if (game->step == 2)
        window_draw_end(game);
    if (game->step == 3)
        window_draw_break(game);
    if (game->step == 4)
        display_map_menu(game);
    sfRenderWindow_display(game->gui->window);
}

void window_draw_start(struct game *game)
{
    sfSprite_setPosition(game->gui->sprites->play, get_position(900, 480));
    sfSprite_setPosition(game->gui->sprites->select, get_position(350, 450));
    display_anim(game);
    display_obstacles(game);
    display_menu(game);
}

void window_draw_game(struct game *game)
{
    sfSprite_setPosition(game->player->sprite,
                         get_position(game->player->x, game->player->y));
    display_anim(game);
    display_obstacles(game);
    draw_sprite(game, game->player->sprite);
    draw_text(game, game->gui->texts->score_field);
    draw_text(game, game->gui->texts->score);
}

void window_draw_break(struct game *game)
{
    sfSprite_setPosition(game->gui->sprites->back, get_position(1415, 13));
    display_anim(game);
    display_obstacles(game);
    draw_sprite(game, game->player->sprite);
    draw_sprite(game, game->gui->sprites->back);
    draw_text(game, game->gui->texts->back);
    draw_text(game, game->gui->texts->score_field);
    draw_text(game, game->gui->texts->score);
}

void window_draw_end(struct game *game)
{
    display_anim(game);
    draw_sprite(game, game->player->sprite);
    draw_text(game, game->gui->texts->title);
    draw_text(game, game->gui->texts->game_over);
    draw_text(game, game->gui->texts->score_field);
    draw_text(game, game->gui->texts->score);
    display_obstacles(game);
    display_end_menu(game);
}
