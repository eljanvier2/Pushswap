/*
** EPITECH PROJECT, 2021
** print funct
** File description:
** printing functions for pushswap
*/

#include "linked_list.h"
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
