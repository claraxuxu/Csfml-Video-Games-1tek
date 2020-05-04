/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** display the number given as a parameter
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int n;
    int var = 0;

    if (nb < 0) {
        my_putchar('-');
        if (nb == - 2147483648) {
            nb = 214748364;
            var = 8;
        }
        else
            nb = -nb;
    }
    n = nb % 10;
    if (nb != n)
        my_put_nbr((nb - n) / 10);
    my_putchar(n + 48);

    if (var)
        my_putchar(var + 48);

    return (n);
}
