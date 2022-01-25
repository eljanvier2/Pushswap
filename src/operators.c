/*
** EPITECH PROJECT, 2021
** operators
** File description:
** every operator used to sort lists
*/

#include "linked_list.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

test_t *rra_op(test_t **head)
{
    if ((*head)->next == NULL)
        return NULL;
    test_t *tmp = (*head);
    test_t *tmp2 = (*head)->next;

    while (tmp->next != NULL)
        tmp = tmp->next;
    (*head)->next = NULL;
    tmp->next = (*head);
    my_putstr("rra");
    my_putchar(' ');
    return tmp2;
}

void pb_op(test_t **head1, test_t **head2)
{
    test_t *tmp = *head1;

    if ((*head1) != NULL) {
        (*head1) = (*head1)->next;
        tmp->next = (*head2);
        (*head2) = tmp;
    }
    my_putstr("pb");
    my_putchar(' ');
}

void pa_op(test_t **head2, test_t **head1)
{
    test_t *tmp = *head1;

    if ((*head1) != NULL) {
        (*head1) = (*head1)->next;
        tmp->next = (*head2);
        (*head2) = tmp;
    }
    if ((*head1) != NULL) {
        my_putstr("pa");
        my_putchar(' ');
    } else {
        my_putstr("pa");
        my_putchar('\n');
    }
}
