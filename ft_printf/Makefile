NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

SRC = ft_printf.c \
		print_functions.c \

OBJ = $(SRC:.c=.o)

$(NAME):	$(OBJ)
	ar rcs $(NAME)	$(OBJ)

all:	$(NAME)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
