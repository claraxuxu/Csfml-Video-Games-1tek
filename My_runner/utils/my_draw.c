/*
** EPITECH PROJECT, 2020
** my_draw
** File description:
** draw part
*/

#include "runner.h"

void draw_text(struct game *game, const sfText *text)
{
    sfRenderWindow_drawText(game->gui->window, text, NULL);
}
void draw_sprite(struct game *game, const sfSprite *sprite)
{
    sfRenderWindow_drawSprite(game->gui->window, sprite, NULL);
}
void set_sprite_position(sfSprite *sprite, const int x, const int y)
{
    sfSprite_setPosition(sprite, get_position(x, y));
}
