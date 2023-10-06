NAME = push_swap
SRC_DIR = src
OBJ_DIR = .objs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =	$(SRC_DIR)/main.c \
				$(SRC_DIR)/stack_utilis.c \
				$(SRC_DIR)/stack_utilis1.c \
				$(SRC_DIR)/index.c \
				$(SRC_DIR)/actions/actions.c \
				$(SRC_DIR)/actions/actions1.c \
				$(SRC_DIR)/actions/actions2.c \
				$(SRC_DIR)/actions/actions_utilis.c \
				$(SRC_DIR)/sorts/sorts_utilis.c \
				$(SRC_DIR)/sorts/sort.c \
				$(SRC_DIR)/sorts/sort3_utilis.c \
				$(SRC_DIR)/sorts/sort5_utilis.c \
				$(SRC_DIR)/sorts/radix_sort.c \

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC = clang
HEAD = -I./inc -I./$(LIBFT_DIR)
CFLAGS = -Wall -Werror -Wextra -g
LFLAGS = -L ./$(LIBFT_DIR) -lft
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(LIBFT):
		@make -C $(LIBFT_DIR)

clean:
		@make clean -C $(LIBFT_DIR)
		@$(RM) $(OBJ_DIR)

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re