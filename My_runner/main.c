/*
** EPITECH PROJECT, 2020
** main
** File description:
** main file for my runner
*/

#include "runner.h"

int check(struct game *game, const int ac, char *av)
{
    if (ac != 1 && ac != 2)
        exit (84);
    if (ac == 2 && av[0] == '-') {
        if (av[1] == 'i')
            run(game);
        if (game->step != 1) {
            game->options->custom_path = av;
            game->options->custom = 1;
            run(game);
            parse_map(game);
        }
    }
    return (0);
}
void run(struct game *game)
{
    free_all_obstacles(game);
    game->score = 0;
    game->step = 1;
    play_random_music(game);
}
void get_help(void)
{
    my_putstr("Finite runner created with CSFML.\n\n");
    my_putstr("USAGE\n ./my_runner map.txt\n\n\n");
    my_putstr("OPTIONS\n -i\t\t   launch the game in infinity mode.\n");
    my_putstr(" -h\t\t   print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n  SPACE_KEY\t   jump.\n");
    exit(0);
}
int main(int ac, char **av)
{
    const int screen_width = 1536;
    const int screen_height = 865;
    char *app_name = "Clara's Runner";
    struct game *game;

    if (ac == 2 && av[1][0] == '-')
        if (av[1][1] == 'h')
            get_help();
    game = get_game_instance(screen_width, screen_height, app_name);
    check(game, ac, av[1]);
    window_run(game);
    window_dispose(game);
    return (0);
}
