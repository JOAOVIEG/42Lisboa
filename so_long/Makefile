NAME = so_long
SRC_DIR = src
OBJ_DIR = .objs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
GET_NEXT_LINE_DIR = get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/libftgetnextline.a

SRC =	$(SRC_DIR)/main.c \
				$(SRC_DIR)/checks.c \
				$(SRC_DIR)/map_checks.c \

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
CC = clang
HEAD = -I./inc -I./$(LIBFT_DIR) -I./$(FT_PRINTF_DIR) -I./$(GET_NEXT_LINE_DIR)
CFLAGS = -Wall -Werror -Wextra -g
LFLAGS = -L ./$(LIBFT_DIR) -lft -L ./$(FT_PRINTF_DIR) -lftprintf -L ./$(GET_NEXT_LINE_DIR) -lget_next_line
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(LIBFT): $(LIBFT_DIR)
		@make -C $(LIBFT_DIR)

$(FT_PRINTF): $(FT_PRINTF_DIR)
		@make -C $(FT_PRINTF_DIR)

$(GET_NEXT_LINE): $(GET_NEXT_LINE_DIR)
		@make -C $(GET_NEXT_LINE_DIR)

clean:
		@make clean -C $(LIBFT_DIR) $(FT_PRINTF_DIR) $(GET_NEXT_LINE_DIR)
		@$(RM) $(OBJ_DIR)

fclean: clean
		@make fclean -C $(LIBFT_DIR) $(FT_PRINTF_DIR) $(GET_NEXT_LINE_DIR)
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re