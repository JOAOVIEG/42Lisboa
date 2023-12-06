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

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)
		@echo "$(GREEN)$(NAME) is ready!$(DEFAULT)"

$(NAME): $(OBJS)
		@echo "$(YELLOW)Compiling libraries...$(DEFAULT)"
		@make -C $(LIB_DIR)/libft
		@make -C $(FT_PRINTF_DIR)
		@echo "$(YELLOW)Compiling $(NAME)...$(DEFAULT)"
		@cc $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

clean:
		@echo "$(ORANGE)Cleaning object files...$(DEFAULT)"
		@make clean -C $(LIB_DIR)/libft
		@make clean -C $(FT_PRINTF_DIR)
		@rm -f $(OBJS)
		@rm -f $(LIBFT)
		@rm -f $(FT_PRINTF)

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