/*
** EPITECH PROJECT, 2019
** music
** File description:
** music for myhunter
*/

#include "../include/my.h"

void analyse_event(window_t *wind, sfEvent *event, sprite_t *sprite)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(wind->window);
    if (event->mouseButton.type == sfEvtMouseButtonReleased)
        pos_mouse(wind, sprite);
}

void pos_mouse(window_t *wind, sprite_t *sprite)
{
    sfVector2i click = sfMouse_getPositionRenderWindow(wind->window);

    if ((click.x >= sprite->pos.x && click.x <= sprite->pos.x + 200)
        && (click.y >= sprite->pos.y && click.y <= sprite->pos.y + 200)
        && sprite->d == 1) {
        success(wind, sprite);
    } else if ((click.x >= sprite->pos.x - 200 && click.x <= sprite->pos.x)
                && (click.y >= sprite->pos.y && click.y <= sprite->pos.y + 200)
                && sprite->d == -1) {
        success(wind, sprite);
    } else
        fail(wind);
}
