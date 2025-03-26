##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Bah on Make le File
##

SRC	=	$(shell find -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME 	=	libhashtable.a

SRC_UNIT	=	$(shell find -name "*.c" ! -name "main.c")

OBJ_UNIT	=	$(SRC_UNIT:.c=.o)

UNIT_NAME = unit_tests

CFLAGS	=	-W -Wall -Wextra

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(UNIT_NAME)
	$(RM) *gcda
	$(RM) *gcno
	$(RM) ./tests/*gcda
	$(RM) ./tests/*gcno

re: fclean all
	$(RM) $(OBJ)

unit_tests_run:	$(UNIT_NAME)

$(UNIT_NAME):	CFLAGS+= --coverage -lcriterion

$(UNIT_NAME):	$(OBJ_UNIT)
	$(CC) $(CFLAGS) -o $(UNIT_NAME) $(OBJ_UNIT)
	./$(UNIT_NAME)
	gcovr . --exclude tests/
	gcovr . --exclude tests/ --branches

clean_unit:
	$(RM) $(OBJ_UNIT)
	$(RM) .$(UNIT_NAME)
	$(RM) *gcda
	$(RM) *gcno
	$(RM) tests/*gcda
	$(RM) tests/*gcno

tests_run: unit_tests_run
