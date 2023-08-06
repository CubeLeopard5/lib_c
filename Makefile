##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## script to build lib
##

SRC		=	src/main.c		\

NAME	=	lol

OBJ		=	$(SRC:.c=.o)

all:	$(NAME)

FLAGS  = -Wall -Wextra -g3

$(NAME):	$(OBJ)
	make -C ./lib/utils/
	make -C ./lib/string/
	make -C ./lib/array/
	make -C ./lib/linked_list/
	make -C ./tests/
	gcc -o $(NAME) $(SRC) -L./lib -lutils -lstring -larray -llinkedlist -lm $(FLAGS)
clean:
	rm -rf $(OBJ)
	make -C ./lib/utils/ clean
	make -C ./lib/string/ clean
	make -C ./lib/array/ clean
	make -C ./lib/linked_list/ clean
	make -C ./tests/ clean

fclean:	clean
	rm -rf $(NAME)
	make -C ./lib/utils/ fclean
	make -C ./lib/string/ fclean
	make -C ./lib/array/ fclean
	make -C ./lib/linked_list fclean
	make -C ./tests/ fclean
	rm -f lib/libutils.a lib/libstring.a lib/libarray.a lib/liblinkedlist.a

re:	fclean all
