##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

SRC	=	main.c	\
		parser/map_parser_path.c \
		parser/map_parser.c \
		parser/score_parser.c \
		utils/my_draw.c \
		utils/my_get.c \
		utils/my_itc.c \
		utils/my_rnd.c \
		utils/my_str.c \
		window/actions/my_window_actions.c \
		window/actions/my_window_game.c \
		window/entities/my_window_enemies.c \
		window/entities/my_window_entities.c \
		window/entities/my_window_obstacles.c \
		window/entities/my_window_player.c \
		window/events/my_window_events.c \
		window/events/my_window_mouse_moved.c \
		window/events/my_window_mouse_pressed.c \
		window/gui/my_window_display.c \
		window/gui/my_window_components.c \
		window/gui/my_window_draw.c \
		window/gui/my_window_resources.c \
		window/instances/my_window_dispose.c \
		window/instances/my_window_get.c \
		window/music/my_window_music.c \
		window/time/my_window_clock.c \
		window/my_window.c

NAME	=	my_runner

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
