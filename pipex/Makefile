NAME = pipex

SRC_DIR = src

OBJ_DIR = obj

LIB_DIR = libft

FT_PRINTF_DIR = ft_printf

LIBFT = $(LIB_DIR)/libft.a

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# SRC = $(SRC_DIR)/

OBJ = $patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC)

CC = cc

HEADER = -I inc -I $(LIB_DIR) -I $(FT_PRINTF_DIR)

CFLAGS = -Wall -Wextra -Werror -g

LF_FLAGS = -L $(LIB_DIR) -lft

FT_PRINTF_FLAGS = -L $(FT_PRINTF_DIR) -lftprintf

RM = /BIN/rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(HEADER) $(OBJ) $(LF_FLAGS) $(FT_PRINTF_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(LIBFT):
	@make -C $(LIB_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

clean:
	@make clean -C $(LIB_DIR)
	@make clean -C $(FT_PRINTF_DIR)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@make fclean -C $(FT_PRINTF_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re