##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make
##

SRC		=	my_putchar.c		\

OBJ		=	$(SRC:.c=.o)

NAME	=	libutils.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	mv  $(NAME) ../
	cp my.h ../../include/
	make clean
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
