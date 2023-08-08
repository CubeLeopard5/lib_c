##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## script to build lib
##

SRC		=	file_manager_init.c			\
			file_manager_destroy.c		\

OBJ		=	$(SRC:.c=.o)

NAME	=	libfilemanager.a

all:    $(NAME)

$(NAME):    $(OBJ)
	ar rc  $(NAME) $(OBJ)
	mv  $(NAME) ../
	cp file_manager.h ../../include/
	$(MAKE) clean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re