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
			my_revstr.c					\
			my_getnbr.c					\
			my_sort_int_array.c			\
			my_compute_factorial.c		\
			my_compute_power.c			\
			my_compute_square_root.c	\
			my_is_prime.c				\
			my_find_prime_sup.c			\
			my_strcpy.c					\
			my_strncpy.c				\
			my_strstr.c					\
			my_strcasestr.c				\
			my_strcmp.c					\
			my_strncmp.c				\
			my_strupcase.c				\
			my_strlowcase.c				\
			my_strcapitalize.c			\
			my_str_isalpha.c			\
			my_str_isnum.c				\
			my_str_islower.c			\
			my_str_isupper.c			\
			my_str_isprintable.c		\
			my_putnbr_base.c			\
			my_getnbr_base.c			\
			my_strchr.c					\
			my_showstr.c				\
			my_strcat.c					\
			my_strncat.c				\
			my_strdup.c					\
			my_show_word_array.c		\
			my_str_to_word_array.c		\
			convert_base.c				\
			get_color.c					\
			swap_endian_color.c			\

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
