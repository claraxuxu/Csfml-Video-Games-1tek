/*
** EPITECH PROJECT, 2019
** struct
** File description:
** my_hunter
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct window {
    sfVideoMode size;
    sfRenderWindow* window;
    char const *title;
    int score;
    int missed;
    int i;
} window_t;

typedef struct fond{
    sfTexture *texture;
    sfSprite *wall;
} font_t;

typedef struct sprite {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect cut;
    sfVector2f pos;
    sfVector2f speed;
    int d;
    int y;
} sprite_t;

typedef struct clock {
    sfClock *clock;
    sfTime time;
    float seconds;
} clock_s;
#endif

void success(window_t *, sprite_t *);
void fail(window_t *);
void move_monster(sprite_t *);
void set_clock(sprite_t *, clock_s *);
void create_sprite();
void create_background(font_t *, sprite_t *);
void show(window_t *, font_t *, sprite_t *, sfSprite*);
void pos_mouse(window_t *, sprite_t *);
void analyse_event(window_t *, sfEvent *, sprite_t *);
void set_struct(window_t *);

int my_strlen (char const *);
int my_putstr(char const *);
int my_put_nbr(int);
void my_putchar(char);
int my_hunter(window_t *, sprite_t *, font_t *, clock_s *);
