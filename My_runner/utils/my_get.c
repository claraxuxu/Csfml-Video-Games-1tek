/*
** EPITECH PROJECT, 2020
** my_get
** File description:
** instance fonctions
*/

#include "runner.h"

struct game *get_game_instance(const int width, const int height, char *name)
{
    const int obs_len = 500;
    struct game *game = malloc(sizeof(struct game));

    if (game == NULL)
        exit (84);
    game->obstacles = malloc(sizeof(struct entity) * obs_len);
    if (game->obstacles == NULL)
        exit (84);
    game->gui = get_gui_instance(width,height,name);
    game->options = get_options();
    game->won = 0;
    game->score = 0;
    game->step = 0;
    return (game);
}
struct gui *get_gui_instance(int width, int height, char *name)
{
    struct gui *gui = malloc(sizeof(struct gui));
    sfVideoMode mode = {width, height, 32};

    if (gui == NULL)
        exit (84);
    gui->window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    gui->sprites = malloc(sizeof(struct gui_sprites));
    gui->texts = malloc(sizeof(struct gui_texts));
    if (gui->sprites == NULL || gui->texts == NULL)
        exit (84);
    gui->width = width;
    gui->height = height;
    gui->name = name;
    return (gui);
}

struct entity *get_entity(int id, int x, int y,
                          int value)
{
    struct entity *entity = malloc(sizeof(struct entity));

    if (entity == NULL)
        exit (84);
    entity->id = id;
    entity->x = x;
    entity->y = y;
    entity->value = value;
    return (entity);
}

struct action *get_action(const int height_limit)
{
    struct action *action = malloc(sizeof(struct action));

    if (action == NULL)
        exit (84);
    action->height_limit = height_limit;
    action->jump_speed = 10;
    action->fall_speed = 2;
    action->rotate = 0;
    return (action);
}

struct options *get_options(void)
{
    struct options *options = malloc(sizeof(struct options));

    if (options == NULL)
        exit (84);
    options->custom = 0;
    return (options);
}
