/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** kill cute birds
*/

#include "include/my.h"

void open_window(window_t *window, font_t *back, sprite_t *sprite)
{
    window->size = (sfVideoMode) {1880, 1050, 32};
    char const *title = "Hunt Cute Bird";
    window->window = sfRenderWindow_create(window->size, title, sfResize |
                                            sfClose, NULL);
    window->score = 0;
    back->texture = sfTexture_createFromFile("cuties/map2.png", NULL);
    back->wall = sfSprite_create();
    create_sprite(sprite);
}

void create_sprite(sprite_t *sprite)
{
    sprite->texture = sfTexture_createFromFile("cuties/Flybird.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->d = 1;
    sprite->y = rand() % 2;
    sfSprite_setScale(sprite->sprite, (sfVector2f) {1.8,1.8});
    sprite->pos = (sfVector2f) {0.0, sprite->y};
    sprite->speed = (sfVector2f) {0.2, 0.1};
    sprite->cut = (sfIntRect) {0, 0, 55, 163};
}

void set_clock(sprite_t *sprite, clock_s *clock)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    if (clock->seconds > 0.15)
        sprite->cut.left = 55;
    if (clock->seconds > 0.30)
        sprite->cut.left = 108;
    if (clock->seconds > 0.45) {
        sprite->cut.left = 0;
        sfClock_restart(clock->clock);
    }
    move_monster(sprite);
}
void get_event(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}
int main(void)
{
    window_t window;
    sprite_t sprite;
    font_t back;
    clock_s clock;

    clock.clock = sfClock_create();
    open_window(&window,&back,&sprite);
    return (my_hunter(&window, &sprite, &back, &clock));
}
