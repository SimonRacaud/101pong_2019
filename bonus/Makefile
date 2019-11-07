##
## EPITECH PROJECT, 2019
## 101pong_breakout_2019
## File description:
## Project makefile
##

SRC	=	main.c			\
		create_window.c		\
		balle.c			\
		block.c			\
		paddle.c		\
		display_window.c

OBJ	=	$(SRC:.c=.o)

NAME	=	101pong_breakout

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	LIB $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -l csfml-graphics

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY :        clean fclean re
