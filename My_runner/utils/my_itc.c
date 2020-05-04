/*
** EPITECH PROJECT, 2020
** my_itc
** File description:
** basic fonctions
*/

#include "runner.h"

char *my_itc(int nbr)
{
    int len = number_digits(nbr);
    char *result;

    result = malloc(sizeof(char) * len);
    if (result == NULL)
        exit (84);
    result[len] = '\0';
    while (len--) {
        result[len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}
int my_atoi(char *src)
{
    int s = 0;
    int a = 1;

    while (*src == ' ')
        src++;
    if (*src == '+' || *src == '-') {
        if (*src == '-')
            a = -1;
        src++;
    }
    while (*src != '\0' && *src >= '0' && *src <= '9') {
        s = s * 10 + *src - '0';
        src++;
    }
    s = s * a;
    return (s);
}
int number_digits(int nbr)
{
    int n = 1;
    int po = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= po) {
        n++;
        po *= 10;
    }
    return (n);
}
