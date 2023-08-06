##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## script to build lib
##

SRC		=	array_init.c		\
			array_destroy.c		\
			print.c				\

OBJ		=    $(SRC:.c=.o)

NAME	=    libarray.a

all:    $(NAME)

$(NAME):    $(OBJ)
	ar rc  $(NAME) $(OBJ)
	mv  $(NAME) ../
	cp array.h ../../include/
	make clean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all