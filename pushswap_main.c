/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** pushswap main file
*/

#include "linked_list.h"
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
        if (my_getnbr(av[i]) != INT_MIN) {
            head->data = my_getnbr(av[i]);
            head->next = prev_struct;
            prev_struct = head;
        }
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
    if (sorter(&head, &head2) == 84)
        return 84;
    return 0;
}
