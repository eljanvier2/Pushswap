/*
** EPITECH PROJECT, 2021
** tests
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void printlist(test_t *head);
int my_putstr(char const *str);
int my_getnbr(char const *str);

void redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(my_putstr, simple_str_f, .init = redirect_all_std)
{
    my_putstr("bonjour");
    cr_assert_stdout_eq_str("bonjour");
}

Test(printlist, simple_printlist, .init = redirect_all_std)
{
    test_t *testlist = malloc(sizeof(test_t));
    testlist->data = 1;
    testlist->next = malloc(sizeof(test_t));
    testlist->next->data = 2;
    testlist->next->next = malloc(sizeof(test_t));
    testlist->next->next->data = 3;
    testlist->next->next->next = NULL;
    printlist(testlist);
    cr_assert_stdout_eq_str("1\n2\n3\n");
}

Test(my_getnbr, simple_getnbr, .init = redirect_all_std)
{
    my_put_nbr(my_getnbr("123"));
    cr_assert_stdout_eq_str("123");
}

Test(sorter, simple_sort, .init = redirect_all_std)
{
    test_t *head2 = NULL;
    test_t *testlist = malloc(sizeof(test_t));
    testlist->data = 3;
    testlist->next = malloc(sizeof(test_t));
    testlist->next->data = 2;
    testlist->next->next = malloc(sizeof(test_t));
    testlist->next->next->data = 1;
    testlist->next->next->next = NULL;
    sorter(&testlist, &head2);
    cr_assert_stdout_eq_str("rra rra pb rra pb pb pa pa pa\n");
}

Test(sorter, already_sorted, .init = redirect_all_std)
{
    test_t *head2 = NULL;
    test_t *testlist = malloc(sizeof(test_t));
    testlist->data = 1;
    testlist->next = malloc(sizeof(test_t));
    testlist->next->data = 2;
    testlist->next->next = malloc(sizeof(test_t));
    testlist->next->next->data = 3;
    testlist->next->next->next = NULL;
    sorter(&testlist, &head2);
    cr_assert_stdout_eq_str("\n");
}

Test(sorter, simple_empty, .init = redirect_all_std)
{
    test_t *head2 = NULL;
    test_t *testlist = NULL;

    sorter(&testlist, &head2);
    cr_assert_stderr_eq_str("Unable to use given data\n");
}

Test(my_get_nbr, overflow_check, .init = redirect_all_std)
{
    my_getnbr("12345678907654324567");
    cr_assert_stderr_eq_str("Overflow\n");
}

Test(my_get_nbr, negative_check, .init = redirect_all_std)
{
    my_put_nbr(my_getnbr("-12"));
    cr_assert_stdout_eq_str("-12");
}
