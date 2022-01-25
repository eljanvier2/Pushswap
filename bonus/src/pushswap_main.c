/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** pushswap main file
*/

#include "list.h"
#include "my.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

test_t *my_params_to_list(int ac, char * const *av, v_indic_t **v_indicator)
{
    test_t *prev_struct = NULL;
    test_t *head = NULL;
    (*v_indicator)->v_indic = 0;

    for (int i = ac - 1; i > 0; i--) {
        head = malloc(sizeof(test_t));
        if (head == NULL || my_getnbr(av[i]) == INT_MIN)
            return NULL;
        if (my_strcmp(av[i], "-v") != 0) {
            head->data = my_getnbr(av[i]);
            head->next = prev_struct;
            prev_struct = head;
        } else
            (*v_indicator)->v_indic = 1;
    }
    return prev_struct;
}

int main(int ac, char *const *av)
{
    test_t *head;
    test_t *head2 = NULL;
    v_indic_t *v_indicator = malloc(sizeof(int));

    if (ac <= 1) {
        my_putsterr("Unable to find list data\n");
        return 84;
    }
    if ((head = my_params_to_list(ac, av, &v_indicator)) == NULL) {
        my_putsterr("Unable to use given data\n");
        return 84;
    }
    if (v_indicator->v_indic == 0)
        sorter(&head, &head2);
    else
        sorter2(&head, &head2);
    printlist(head);
    return 0;
}
