##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_hunter
##

SRC	=	my_hunter.c	\
		lib/display.c		\
		lib/hunter.c			\
		lib/my_putchar.c	\
		lib/my_putstr.c		\
		lib/my_strlen.c		\
		lib/my_put_nbr.c	\
		lib/event.c		\
		lib/move_monsters.c

NAME	=	my_hunter

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I include

LDFLAGS	=	-l csfml-graphics -l csfml-audio -l csfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f lib/*.o

re:	fclean all
