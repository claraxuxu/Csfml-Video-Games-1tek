/*
** EPITECH PROJECT, 2020
** my_rnd
** File description:
** random sys
*/

#include "runner.h"

int crand(int a, int b)
{
    return (rand() % (b - a) + a);
}

char *get_sentence(const int won)
{
    if (won == 1)
        return ("Game Over");
    return ("VICTORY");
}

void get_random_entity(struct entity *entity, struct game *game)
{
    char path[30] = "resources/obs_1.png";
    char path_e[27] = "resources/enemy_1.png";

    if (entity->skin == 3) {
        path_e[22] = crand(1, 3) + '0';
        entity->sprite = get_sprite(path_e);
    } else
        entity->sprite = get_sprite(path);
    sfSprite_setPosition(entity->sprite, get_position(entity->x,
                                                      entity->y));
    game->obstacles[game->obstacles_len] = entity;
    game->obstacles_len++;
}
