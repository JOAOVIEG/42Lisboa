NAME = pipex

SRC_DIR = src

BONUS_SRC_DIR = pipex_bonus/src_bonus

LIB_DIR = inc

BONUS_LIB_DIR = pipex_bonus/inc_bonus

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

BONUS_SRCS = $(BONUS_SRC_DIR)/main_bonus.c \
			$(BONUS_SRC_DIR)/file_handler_bonus.c \
			$(BONUS_SRC_DIR)/pipex_bonus.c \
			$(BONUS_SRC_DIR)/command_handle_bonus.c \

BONUS_OBJS := $(BONUS_SRCS:.c=.o)

BONUS_HEAD = -I./pipex_bonus/inc_bonus

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	@echo "$(YELLOW)Compiling $(NAME)...$(DEFAULT)"
	@cc $(CFLAGS) $(HEAD) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)


$(LIBFT):
	@echo "$(YELLOW)Compiling $(LIBFT)...$(DEFAULT)"
	@make -s -C $(LIB_DIR)/libft

$(FT_PRINTF):
	@echo "$(YELLOW)Compiling $(FT_PRINTF)...$(DEFAULT)"
	@make -s -C $(FT_PRINTF_DIR)

bonus: $(BONUS_OBJS) $(LIBFT)
	@echo "$(YELLOW)Compiling bonus...$(DEFAULT)"
	@cc $(CFLAGS) $(BONUS_HEAD) $(BONUS_OBJS) $(LIBFT) -o $(NAME)


val: $(NAME)
	@echo "$(GREEN)Running valgrind...$(DEFAULT)"
	@valgrind --track-fds=yes ./pipex Makefile "ls -l" "sleep 5" outfile.txt

clean:
	@echo "$(ORANGE)Cleaning object files...$(DEFAULT)"
	@make clean -s -C $(LIB_DIR)/libft
	@make clean -s -C $(FT_PRINTF_DIR)
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)

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