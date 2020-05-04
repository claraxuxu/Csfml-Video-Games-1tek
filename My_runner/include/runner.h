/*
** EPITECH PROJECT, 2020
** runner
** File description:
** header for my runner
*/

#ifndef _MY_H_
#define _MY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define select_path ("resources/infinity.png")
#define play_path ("resources/player_button.png")
#define home_path ("resources/menu_button.png")
#define back_path ("resources/back_button.png")
#define font_path ("resources/pixelates.ttf")

struct game {
    struct entity *player;
    struct entity **obstacles;
    struct gui *gui;
    struct action *action;
    struct options *options;
    sfMusic *music;
    int score;
    int won;
    int speed;
    int step;
    int highest;
    int obstacles_len;
    int maps_len;
};

struct gui {
    struct gui_sprites *sprites;
    struct gui_texts *texts;
    sfRenderWindow *window;
    sfFont *pixel_font;
    char *name;
    int color;
    int bg_abs;
    int floor_abs;
    int width;
    int height;
};

struct gui_sprites {
    sfSprite *bg;
    sfSprite *bg2;
    sfSprite *floor;
    sfSprite *floor2;
    sfSprite *play;
    sfSprite *select;
    sfSprite *menu;
    sfSprite *back;
};

struct gui_texts {
    sfText *title;
    sfText *play_field;
    sfText *select_field;
    sfText *score_field;
    sfText *menu_field;
    sfText *game_over;
    sfText *score;
    sfText *back;
    sfText **maps_fields;
};

struct options {
    char *custom_path;
    int custom;
};

struct entity {
    sfSprite *sprite;
    int id;
    int x;
    int y;
    int value;
    int skin;
};

struct action {
    int height_limit;
    int jump_speed;
    int fall_speed;
    int rotate;
};

void run(struct game *game);
int check(struct game *game, const int ac, char *av);
void get_help(void);

char *prepare_path(const char *file, const char *directory);
void map_selected(struct game *game, const int i);
char *my_strcat(char *dest, const char *src);
void parse_map(struct game *game);
void parse_line(struct game *game, const char *line, const int len,
                const int y);
void check_char(struct game *game, const char c);
void list_maps(struct game *game);
int window_contain_map(const sfText *text, const sfVector2f pos);
void save_score(struct game *game);
void read_score(struct game *game);
void append_score(struct game *game, const char *buf, FILE *file);
void draw_text(struct game *game, const sfText *text);
void draw_sprite(struct game *game, const sfSprite *sprite);
void set_sprite_position(sfSprite *sprite, const int x,
                         const int y);
struct game *get_game_instance(const int width, const int height, char *name);
struct gui *get_gui_instance(int width, int height, char *name);
struct entity *get_entity(const int id, const int x, const int y,
                          const int value);
struct action *get_action(const int height_limit);
struct options *get_options(void);
char *my_itc(int nbr);
int my_atoi(char *str);
int number_digits(int nbr);
int crand(int a, int b);
void get_random_entity(struct entity *entity, struct game *game);
char *get_sentence(const int won);
void my_put_char(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, char const *src, int n);
void progressive_speed_jump(struct game *game);
void progressive_speed_fall(struct game *game);
void game_ended_colision(struct game *game);
void game_won(struct game *game);
void spawn_random_enemy(struct game *game, int height);
void get_random_enemy(struct entity *entity, struct game *game);
int entity_colision(struct game *game, struct entity *entity);
void spawn_random_obstacle(struct game *game);
int spawn_obstacles(sfClock *obs_clock, struct game *game);
int randomize_obs(struct game *game, int block, const int start_abs);
void free_all_obstacles(struct game *game);
void free_first_obstacle(struct game *game);
int manage_player_move(sfClock *game_clock, struct game *game);
void manage_player_jump(struct game *game, const int height_limit);
void manage_progressive_speed(struct game *game);
int block_below_player(struct game *game);
int block_on_player(struct game * game);
void window_events(sfEvent event, struct game *game);
void window_key_pressed(sfEvent event, struct game *game);
void window_mouse_pressed(sfEvent event, struct game *game);
void window_mouse_moved(sfEvent event, struct game *game);
int window_contain_point(sfSprite *sprite, const sfVector2f pos,
                         const int size);
void mouse_moved_start(struct game *game, const sfVector2f mouse);
void mouse_moved_end(struct game *game, const sfVector2f mouse);
void mouse_pressed_break_ext(struct game *game, const sfVector2f mouse);
void mouse_pressed_start(struct game *game, const sfVector2f mouse);
void mouse_pressed_start_ext(struct game *game, const sfVector2f mouse);
void mouse_pressed_end(struct game *game, const sfVector2f mouse);
void mouse_pressed_break(struct game *game, const sfVector2f mouse);
void mouse_pressed_maps(struct game *game, const sfVector2f mouse);
void window_load_components(struct game *game);
void window_load_sprites(struct game *game);
void window_load_texts(struct game *game);
void window_load_extented_texts(struct game *game);
void window_load_fonts(struct game *game);
void display_anim(struct game *game);
void display_obstacles(struct game *game);
void display_menu(struct game *game);
void display_end_menu(struct game *game);
void display_map_menu(struct game *game);
void window_draw(struct game *game);
void window_draw_start(struct game *game);
void window_draw_game(struct game *game);
void window_draw_break(struct game *game);
void window_draw_end(struct game *game);
void resources_load_bg(struct game *game);
void resources_load_blocks(struct game *game);
void resources_load_floors(struct game *game);
void resources_load_fonts(struct game *game);
void ressources_load_gui(struct game *game);
void dispose_gui(struct game *game);
void dispose_sprites(struct game *game);
void dispose_texts(struct game *game);
sfSprite *get_sprite(const char *file_path);
sfVector2f get_position(const int x, const int y);
sfIntRect get_rect(const int top, const int left, const int width,
                   const int height);
sfText *get_text(sfVector2f pos, const char *value, const int size,
                 sfFont *font);
void play_random_music(struct game *game);
void stop_music(struct game *game);
void play_music(struct game *game);
int manage_scrolling(sfClock *game_clock, struct game *game);
void manage_obstacles_scrolling(struct game *game);
void window_run(struct game *game);
void window_run_start(sfClock *game_clock, sfClock *obs_clock,
                      struct game *game);
void window_run_game(sfClock *game_clock, sfClock *obs_clock,
                     struct game *game);
void window_dispose(struct game *game);
#endif
