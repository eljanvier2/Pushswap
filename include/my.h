/*
** EPITECH PROJECT, 2021
** header
** File description:
** headers
*/

#include "list.h"

#ifndef MY_H_
    #define MY_H_

test_t *rra_op(test_t **head);
void pb_op(test_t **head1, test_t **head2);
void pa_op(test_t **head2, test_t **head1);
int my_getnbr(char const *str);
int my_putsterr(char const *str);
void printlist(test_t *head);
test_t *my_params_to_list(int ac, char * const *av, v_indic_t **v_indicator);
int smallest_finder(test_t **head1);
void rotate(test_t **head, int smallest);
int sorter(test_t **head1, test_t **head2);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
void my_putchar(char c);
int my_put_nbr(int nb);
int already_sorted(test_t **head);

#endif
