##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make
##

SRC		=	my_putchar.c				\
			my_isneg.c					\
			my_print_comb.c				\
			my_put_nbr.c				\
			my_swap.c					\
			my_putstr.c					\
			my_strlen.c					\
			my_evil_str.c				\
			my_getnbr.c					\
			my_sort_int_array.c			\
			my_compute_factorial.c		\
			my_compute_power.c			\

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
