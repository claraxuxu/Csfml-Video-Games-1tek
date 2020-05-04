/*
** EPITECH PROJECT, 2019
** move_monsters
** File description:
** movement of birds
*/

#include "../include/my.h"

void move_monster(sprite_t *sprite)
{
    sfVector2f vector = {-1, 1};

    sprite->pos.x += sprite->speed.x;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    if (sprite->pos.x > 1880 + 50 || sprite->pos.x < 0 - 50) {
        sprite->speed.x *= -1;
        sprite->d *= -1;
        sfSprite_scale(sprite->sprite, vector);
    }
}
