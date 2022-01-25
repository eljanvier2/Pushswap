/*
** EPITECH PROJECT, 2021
** my_getnmbr
** File description:
** task 05
*/

#include <unistd.h>
#include <limits.h>
#include "my.h"

int check_overflow(long fin_nmbr, char const *str, long stamp, int i)
{
    int j = 0;
    int neg_cont = 1;

    if (str[i] == '-') {
        j++;
        neg_cont = -1;
    }
    while (str[j] >= '0' && str[j] <= '9') {
        stamp = str[j] - 48;
        fin_nmbr = fin_nmbr * 10 + stamp;
        i++;
        j++;
        if (fin_nmbr > 2147483647 || fin_nmbr < -2147483648)
            return INT_MIN;
    }
    return (fin_nmbr * neg_cont);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int j = 1;
    int stamp = 0;
    long fin_nmbr = 0;

    while (str[i] != '\0') {
        if (check_overflow(fin_nmbr, str, stamp, i) == INT_MIN) {
            my_putsterr("Overflow\n");
            return INT_MIN;
        }
        fin_nmbr = check_overflow(fin_nmbr, str, stamp, i);
        if (fin_nmbr != 0)
            return (fin_nmbr * j);
        if (str[i] == '-')
            j = j * (-1);
        i++;
    }
    return (fin_nmbr * j);
}

int my_getnbr2(char const *str)
{
    int i = 0;
    int j = 1;
    int stamp = 0;
    long fin_nmbr = 0;

    while (str[i] != '\n') {
        if (check_overflow(fin_nmbr, str, stamp, i) == 0)
            return 0;
        fin_nmbr = check_overflow(fin_nmbr, str, stamp, i);
        if (fin_nmbr != 0)
            return (fin_nmbr * j);
        if (str[i] == '-')
            j = j * (-1);
        i++;
    }
    return (fin_nmbr * j);
}
