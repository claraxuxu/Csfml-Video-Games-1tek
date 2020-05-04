/*
** EPITECH PROJECT, 2019
** my_putstrc
** File description:
** for day07
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}