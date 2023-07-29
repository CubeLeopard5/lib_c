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
	gcc -o $(NAME) $(SRC) -L./lib -lutils -lstring -lm $(FLAGS)
clean:
	rm -rf $(OBJ)
	make -C ./lib/utils/ clean
	make -C ./lib/string/ clean

fclean:	clean
	rm -rf $(NAME)
	make -C ./lib/utils/ fclean
	make -C ./lib/string/ fclean
	rm -f lib/libutils.a lib/libstring.a

re:	fclean all
