/*
** EPITECH PROJECT, 2021
** print funct
** File description:
** printing functions for pushswap
*/

#include "list.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void printlist(test_t *head)
{
    while (head != NULL) {
        my_put_nbr(head->data);
        my_putchar('\n');
        head = head->next;
    }
}

void v_printer(test_t **head1, test_t **head2)
{
    my_putstr("\nla :\n");
    printlist(*head1);
    my_putstr("\nlb :\n");
    printlist(*head2);
    my_putchar('\n');
}

void v_printer_single(test_t **head1)
{
    my_putstr("\nla :\n");
    printlist(*head1);
    my_putchar('\n');
}
