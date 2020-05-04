/*
** EPITECH PROJECT, 2020
** my_window_displays
** File description:
** display all the module in game page
*/

#include "runner.h"

void display_anim(struct game *game)
{
    draw_sprite(game, game->gui->sprites->bg);
    draw_sprite(game, game->gui->sprites->bg2);
    draw_sprite(game, game->gui->sprites->floor);
    draw_sprite(game, game->gui->sprites->floor2);
}

void display_obstacles(struct game *game)
{
    for (int i = 0; i < game->obstacles_len; i++)
        draw_sprite(game, game->obstacles[i]->sprite);
}

void display_menu(struct game *game)
{
    draw_sprite(game, game->gui->sprites->select);
    draw_sprite(game, game->gui->sprites->play);
    draw_text(game, game->gui->texts->title);
    draw_text(game, game->gui->texts->select_field);
    draw_text(game, game->gui->texts->play_field);
    draw_sprite(game, game->player->sprite);
}

void display_end_menu(struct game *game)
{
    sfSprite_setPosition(game->gui->sprites->menu, get_position(600,420));
    draw_sprite(game, game->gui->sprites->menu);
    draw_text(game, game->gui->texts->menu_field);
}

void display_map_menu(struct game *game)
{
    display_anim(game);
    display_obstacles(game);
    sfSprite_setPosition(game->player->sprite, get_position(400, 13));
    sfSprite_setPosition(game->gui->sprites->back, get_position(1415, 13));
    draw_text(game,game->gui->texts->back);
    draw_sprite(game,game->gui->sprites->back);
    draw_sprite(game,game->player->sprite);
    for (int i = 0; i < game->maps_len; i++)
        draw_text(game,game->gui->texts->maps_fields[i]);
}
