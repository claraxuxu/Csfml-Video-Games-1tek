/*
** EPITECH PROJECT, 2020
** my_window_entities
** File description:
** movements
*/

#include "runner.h"

int entity_colision(struct game *game, struct entity *entity)
{
    const int block_size = 77;

    if ((game->player->y + block_size <= entity->y + block_size &&
         game->player->y + block_size >= entity->y + 10) &&
        (game->player->x + block_size >= entity->x + 10 &&
         game->player->x + block_size <= entity->x + block_size - 10))
        return (1);
    if ((game->player->y + block_size <= entity->y + block_size &&
         game->player->y + block_size >= entity->y + 10) &&
        (game->player->x >= entity->x + 10 &&
         game->player->x <= entity->x + block_size - 10))
        return (1);
    return (0);
}
