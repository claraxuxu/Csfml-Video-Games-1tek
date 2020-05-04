/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** for Day7
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
