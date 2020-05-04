/*
** EPITECH PROJECT, 2017
** display
** File description:
** succeed or not
*/

#include "../include/my.h"

void success(window_t *wind, sprite_t *sprite)
{
    my_putstr("Yay!\n");
    wind->score += 1;
    if (sprite->speed.x > 0)
        sprite->speed.x += 0.18;
    else
        sprite->speed.x -= 0.18;
    sprite->y = rand() % 388;
    sprite->pos = (sfVector2f) {0.0, sprite->y};
    sfSprite_setPosition(sprite->sprite, sprite->pos);
}

void fail(window_t *wind)
{
    my_putstr("Failed \n");
    wind->i += 1;
    if (wind->i == 3) {
        my_putstr("Final Score: ");
        my_put_nbr(wind->score);
        my_putchar('\n');
        my_putstr("Failed: ");
        my_put_nbr(wind->i);
        my_putstr(" times\n");
        sfRenderWindow_close(wind->window);
    }
}
