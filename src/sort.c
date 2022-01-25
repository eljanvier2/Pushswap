/*
** EPITECH PROJECT, 2021
** step4
** File description:
** right to left
*/

#include "linked_list.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int smallest_finder(test_t **head1)
{
    test_t *tmp = (*head1);
    int smallest = 2147483647;

    while (tmp != NULL) {
        if (smallest > tmp->data)
            smallest = tmp->data;
        tmp = tmp->next;
    }
    return smallest;
}

void rotate(test_t **head, int smallest)
{
    while ((*head)->data != smallest)
        (*head) = rra_op(head);
}

int already_sorted(test_t **head)
{
    test_t *tmp = *head;

    int checker = (*head)->data;
    while (tmp != NULL) {
        if (checker > tmp->data)
            return 1;
        checker = tmp->data;
        tmp = tmp->next;
    }
    return 0;
}

int sorter(test_t **head1, test_t **head2)
{
    test_t *tmp = (*head1);
    int smallest = 0;

    if ((*head1) == NULL) {
        my_putsterr("Unable to use given data\n");
        return 84;
    }
    if (already_sorted(head1) == 0) {
        my_putchar('\n');
        return 0;
    }
    while ((*head1) != NULL) {
        rotate(head1, smallest_finder(head1));
        pb_op(head1, head2);
    }
    while ((*head2) != NULL) {
        pa_op(head1, head2);
    }
    return 0;
}
