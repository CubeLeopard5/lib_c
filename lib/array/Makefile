##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## script to build lib
##

SRC		=	array_init.c		\
			array_destroy.c		\

OBJ		=	$(SRC:.c=.o)

NAME	=	libarray.a

all:    $(NAME)

$(NAME):    $(OBJ)
	ar rc  $(NAME) $(OBJ)
	mv  $(NAME) ../
	cp array.h ../../include/
	$(MAKE) clean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re