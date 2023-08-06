NAME    = 	run_tests

CC		=	gcc

CFLAG	=	-g3 -Wall -Wextra -lcriterion --verbose

SRC 	= 	../lib/utils/my_revstr.c				\
			my_revstr_tests.c						\
			../lib/utils/my_getnbr.c				\
			my_getnbr_tests.c						\

OBJ	 = 	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAG)
	make clean

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)
re: fclean all

.PHONY: all clean fclean re