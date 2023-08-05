##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make
##

SRC		=	my_params_to_list.c				\
			my_list_size.c					\
			my_rev_list.c					\
			my_apply_on_nodes.c				\
			my_apply_on_matching_nodes.c	\
			my_find_node.c					\

OBJ		=	$(SRC:.c=.o)

NAME	=	liblinkedlist.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	mv  $(NAME) ../
	cp linked_list.h ../../include/
	make clean
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
