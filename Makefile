##
## EPITECH PROJECT, 2019
## 101pong_2019
## File description:
## Project makefile
##

SRC	=	main.c				\
		101pong.c			\
		my_put_double.c			\
		extract_parameter.c

OBJ	=	$(SRC:.c=.o)

NAME	=	101pong

CFLAGS	+= -Wall -Wextra -I./include

all:	LIB $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib/my -lm -lmy

LIB :
	make -C ./lib/my

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#tests_run:

.PHONY :        clean fclean re
