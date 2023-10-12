NAME = libftgetnextline.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

SRC = get_next_line_utils.c \
		get_next_line.c \

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
