/*
** EPITECH PROJECT, 2020
** my_str
** File description:
** str fonctions
*/

#include "runner.h"

void my_put_char(char c)
{
    write (1, &c, 1);
}
void my_putstr(const char *str)
{
    write(1, str, my_strlen(str));
}
int my_strlen(const char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}
char *my_strcpy(char *dest, const char *src)
{
    int count = 0;
    char const *cpy = src;

    for (cpy = src; *cpy != '\0'; cpy++)
        count ++;
    for (int j = 0; j <= count; j++)
        dest[j] = src[j];
    return (dest);
}
char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    for (; n > 0 && src[i] != '\0'; i++,n--)
        dest[i] = src[i];
    if (n > 0)
        dest[i++] = '\0';
    return (dest);
}
