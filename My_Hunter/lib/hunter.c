/*
** EPITECH PROJECT, 2017
** move
** File description:
** evet, click events
*/

#include "../include/my.h"

void *music(void)
{
    sfMusic *music;

    music = sfMusic_createFromFile("cuties/mario.ogg");
    sfMusic_play(music);
    return (music);
}
void *cute(void)
{
    sfTexture *texture = sfTexture_createFromFile("cuties/Mario.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite,(sfVector2f){-10,50});
    return (sprite);
}
void show(window_t *wind, font_t *back, sprite_t *sprite, sfSprite *sprite1)
{
    sfSprite_setTexture(back->wall, back->texture, sfTrue);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->cut);
    sfRenderWindow_drawSprite(wind->window, back->wall, NULL);
    sfRenderWindow_drawSprite(wind->window, sprite->sprite, NULL);
    sfRenderWindow_drawSprite(wind->window, sprite1, NULL);
}
void kill(sfMusic *music1, sfSprite *sprite1, window_t *wind)
{
    sfMusic_destroy(music1);
    sfSprite_destroy(sprite1);
    sfRenderWindow_destroy(wind->window);
}

int my_hunter(window_t *wind, sprite_t *sprite, font_t *back, clock_s *clock)
{
    sfEvent event;
    sfVector2f change;
    change.x = 600;
    change.y = 650;
    sfSprite *sprite1 = cute();
    sfMusic* music1 = music();

    while (sfRenderWindow_isOpen(wind->window)) {
        sfRenderWindow_display(wind->window);
        show(wind, back, sprite, sprite1);
        set_clock(sprite, clock);
        while (sfRenderWindow_pollEvent(wind->window, &event))
            analyse_event(wind, &event, sprite);
        if (change.y < -15)
            change.y = 650;
        change.y -= 1;
        sfSprite_setPosition(sprite1,change);
    }
    kill(music1,sprite1,wind);
    return (84);
}
