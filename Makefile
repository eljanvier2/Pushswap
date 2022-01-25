##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task 01
##

SRC	=	./src/print_funct.c	\
		./src/operators.c	\
		./src/sort.c	\
		./src/my_putstr.c	\
		./src/my_get_nbmr.c	\
		./src/my_put_nbr.c	\
		./src/my_strcmp.c	\

TEST_SRC	=	test_src/unit_tests.c	\
				./src/print_funct.c	\
				./src/operators.c	\
				./src/sort.c	\
				./src/my_putstr.c	\
				./src/my_get_nbmr.c	\
				./src/my_put_nbr.c	\

NAME 	=	push_swap

CPPFLAGS =	-I./include -g

TESTS_FLAGS = --coverage -lcriterion

all:
	gcc -o $(NAME) pushswap_main.c $(SRC) $(CPPFLAGS) -g

clean:
	rm -rf ./sources/*.o

cover:
		mkdir -p crit_result
		gcovr --exclude tests/ --html --html-details -o crit_result/cov.html
		gcovr --branches --exclude tests/

fclean: clean
	rm -rf $(NAME)
	rm -rf ../$(NAME)
	rm -rf unit*
	rm -rf crit_result

re:	fclean all

tests_run:
	rm -rf unit*
	gcc -o unit_tests $(TEST_SRC) $(TESTS_FLAGS) $(CPPFLAGS)
	./unit_tests
	gcovr

auteur:
	echo $(USER) > auteur

.PHONY:	all clean fclean re auteur tests_run
