/*
** EPITECH PROJECT, 2020
** my_window_components
** File description:
** game loading page
*/

#include "runner.h"

void window_load_components(struct game *game)
{
    window_load_sprites(game);
    window_load_fonts(game);
    window_load_texts(game);
    window_load_extented_texts(game);
}
void window_load_sprites(struct game *game)
{
    resources_load_bg(game);
    resources_load_blocks(game);
    resources_load_floors(game);
    ressources_load_gui(game);
}
void window_load_texts(struct game *game)
{
    game->gui->texts->title = get_text(get_position(275, 140),
                                       "Clara's Cute Runner", 80,
                                       game->gui->pixel_font);
    game->gui->texts->select_field = get_text(get_position(290, 620),
                                              "Select level", 40,
                                              game->gui->pixel_font);
    game->gui->texts->play_field = get_text(get_position(850, 620),
                                            "Infinity Mode", 40,
                                            game->gui->pixel_font);
    game->gui->texts->menu_field = get_text(get_position(680, 720),
                                            "Menu", 40,
                                            game->gui->pixel_font);
    game->gui->texts->score_field = get_text(get_position(10, 0),
                                             "Score", 30,
                                             game->gui->pixel_font);
    game->gui->texts->score = get_text(get_position(165, 0),
                                       "0", 30, game->gui->pixel_font);
    game->gui->texts->game_over = get_text(get_position(350, 300),
                                           get_sentence(game->won), 45,
                                           game->gui->pixel_font);
}
void window_load_extented_texts(struct game *game)
{
    game->gui->texts->back = get_text(get_position(1400, 80),
                                      "Back", 40, game->gui->pixel_font);
}
void window_load_fonts(struct game *game)
{
    resources_load_fonts(game);
}
