/*
** EPITECH PROJECT, 2020
** my_window_resource
** File description:
** chose images
*/

#include "runner.h"

void resources_load_bg(struct game *game)
{
    char bg_path[22] = "resources/bg_1.png";
	
    game->gui->sprites->bg = get_sprite(bg_path);
    game->gui->sprites->bg2 = get_sprite(bg_path);
}

void resources_load_blocks(struct game *game)
{
    char block_path[28] = "resources/cutie.png";

    game->player->sprite = get_sprite(block_path);
    sfSprite_setPosition(game->player->sprite, get_position(game->player->x
                                                            , game->player->y)
        );
}

void resources_load_floors(struct game *game)
{
    char floor_path[28] = "resources/floor_1.png";

    game->gui->sprites->floor = get_sprite(floor_path);
    game->gui->sprites->floor2 = get_sprite(floor_path);
}

void ressources_load_gui(struct game *game)
{
    game->gui->sprites->select = get_sprite(select_path);
    game->gui->sprites->play = get_sprite(play_path);
    game->gui->sprites->menu = get_sprite(home_path);
    game->gui->sprites->back = get_sprite(back_path);
}

void resources_load_fonts(struct game *game)
{
    game->gui->pixel_font = sfFont_createFromFile(
        font_path);
}
