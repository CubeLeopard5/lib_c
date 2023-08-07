##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## script to build lib
##

SRC		=	src/main.c		\

NAME	=	my_program

OBJ		=	$(SRC:.c=.o)

LIB_DIRS		=	./lib/utils ./lib/string ./lib/array ./lib/linked_list
TESTS_DIR		=	./tests

LIB_NAMES     	=	utils string array linkedlist
LIBRAIRIES    	=	$(LIB_NAMES:%=-l%)
STATIC_LIBS   	=	$(LIB_NAMES:%=lib/lib%.a)

FLAGS  = -Wall -Wextra -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	@for dir in $(LIB_DIRS); do 	\
		$(MAKE) -C $$dir; 			\
	done
	$(MAKE) -C $(TESTS_DIR)
	gcc -o $(NAME) $(SRC) -L./lib $(LIBRAIRIES) -lm $(FLAGS)

clean:
	rm -rf $(OBJ)
	@for dir in $(LIB_DIRS); do 	\
		$(MAKE) -C $$dir clean;		\
	done
	$(MAKE) -C $(TESTS_DIR) clean

fclean:	clean
	rm -rf $(NAME)
	@for dir in $(LIB_DIRS); do 	\
		$(MAKE) -C $$dir fclean;	\
	done
	$(MAKE) -C $(TESTS_DIR) fclean
	rm -f $(STATIC_LIBS)

re:	fclean all

.PHONY: all clean fclean re