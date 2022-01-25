/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** task 02
*/

#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

void my_puterror(char c)
{
    write (2, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar (str[i]);
        i++;
    }
    return (0);
}

int my_putsterr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_puterror (str[i]);
        i++;
    }
    return (0);
}
