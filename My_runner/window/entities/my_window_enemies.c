/*
** EPITECH PROJECT, 2020
** my_window_enemies
** File description:
** get random cute enemies
*/

#include "runner.h"

void spawn_random_enemy(struct game *game, int height)
{
    const int start_abs = 1600;
    struct entity *entity =
        get_entity(game->obstacles_len, start_abs, height, 0);

    entity->skin = crand(1, 4);
    get_random_enemy(entity, game);
}

void get_random_enemy(struct entity *entity, struct game *game)
{
    char path[27] = "resources/enemy_1.png";

    path[22] = entity->skin + '0';
    entity->sprite = get_sprite(path);
    sfSprite_setPosition(entity->sprite, get_position(entity->x,
                                                      entity->y));
    entity->skin = 3;
    game->obstacles[game->obstacles_len] = entity;
    game->obstacles_len++;
}
