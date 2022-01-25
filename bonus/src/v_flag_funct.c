/*
** EPITECH PROJECT, 2021
** -v flag functions
** File description:
** every -v related function
*/

#include "my.h"
#include "list.h"
#include <stdlib.h>

void rotate_v(test_t **head, int smallest)
{
    while ((*head)->data != smallest)
        (*head) = rra_op_v(head);
}

int sorter2(test_t **head1, test_t **head2)
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
        rotate_v(head1, smallest_finder(head1));
        pb_op(head1, head2);
        v_printer(head1, head2);

    }
    while ((*head2) != NULL) {
        pa_op(head1, head2);
        v_printer(head1, head2);
    }
    return 0;
}

test_t *rra_op_v(test_t **head)
{
    if ((*head)->next == NULL)
        return NULL;
    test_t *tmp = (*head);
    test_t *tmp2 = (*head)->next;

    while (tmp->next != NULL)
        tmp = tmp->next;
    (*head)->next = NULL;
    tmp->next = (*head);
    my_putstr("rra ");
    v_printer_single(head);
    return tmp2;
}
