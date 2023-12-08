NAME = pipex

SRC_DIR = src

LIB_DIR = inc

FT_PRINTF_DIR = $(LIB_DIR)/ft_printf

LIBFT = $(LIB_DIR)/libft/libft.a

FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRCS = $(SRC_DIR)/main.c \
			$(SRC_DIR)/file_handler.c \
			$(SRC_DIR)/pipex.c \
			$(SRC_DIR)/command_handle.c \

OBJS := $(SRCS:.c=.o)

HEAD = -I./inc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	@echo "$(YELLOW)Compiling $(NAME)...$(DEFAULT)"
	@cc $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT):
	@echo "$(YELLOW)Compiling $(LIBFT)...$(DEFAULT)"
	@make -C $(LIB_DIR)/libft

$(FT_PRINTF):
	@echo "$(YELLOW)Compiling $(FT_PRINTF)...$(DEFAULT)"
	@make -C $(FT_PRINTF_DIR)

# val: $(NAME)
# 		@echo "$(GREEN)Running valgrind...$(DEFAULT)"
# 		@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) Makefile "ls -l" "wc -l" outfile.txt
clean:
		@echo "$(ORANGE)Cleaning object files...$(DEFAULT)"
		@make clean -C $(LIB_DIR)/libft
		@make clean -C $(FT_PRINTF_DIR)
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)
		@echo "$(RED)Cleaning $(NAME)...$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re

GREEN = \033[0;32m
RED = \033[0;31m
ORANGE = \033[0;33m
DEFAULT = \033[0m
YELLOW = \033[1;33m