NAME = pipex

LIBFT = libft.a

SRC_DIR = src

BONUS_SRC_DIR = src/bonus

SRCS = $(SRC_DIR)/main.c \
			$(SRC_DIR)/file_handler.c \
			$(SRC_DIR)/pipex.c \
			$(SRC_DIR)/command_handle.c \

BONUS_SRCS = $(BONUS_SRC_DIR)/main_bonus.c \
			$(BONUS_SRC_DIR)/file_handler_bonus.c \
			$(BONUS_SRC_DIR)/pipex_bonus.c \
			$(BONUS_SRC_DIR)/command_handle_bonus.c \
			$(BONUS_SRC_DIR)/init_xpipe_utilis.c \
			$(BONUS_SRC_DIR)/pipex_bonus_utilis.c \
			$(BONUS_SRC_DIR)/pipex_bonus_utilis1.c \

OBJS := $(SRCS:.c=.o)

BONUS_OBJS := $(BONUS_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)
	@echo "$(GREEN)$(NAME) is ready!$(DEFAULT)"

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling library...$(DEFAULT)"
	@make -C ./libft
	@mv ./libft/$(LIBFT) .
	@cc $(CFLAGS) $(OBJS) -L. $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_OBJS)
	@echo "$(YELLOW)Compiling library for bonus...$(DEFAULT)"
	@cc $(CFLAGS) $(BONUS_OBJS) -L. $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Bonus is ready!$(DEFAULT)"

$(LIBFT):
	@echo "$(YELLOW)Compiling library...$(DEFAULT)"
	@make -C ./libft
	@mv ./libft/$(LIBFT) .

val: $(NAME)
	@echo "$(GREEN)Running valgrind...$(DEFAULT)"
	@valgrind --track-fds=yes ./pipex Makefile "ls -l" "sleep 5" outfile.txt

clean:
	@echo "$(ORANGE)Cleaning object files...$(DEFAULT)"
	@make clean -C ./libft
	rm -f $(LIBFT)
	@rm -f $(BONUS_OBJS)
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Cleaning $(NAME)...$(DEFAULT)"

re: fclean all

.PHONY: all clean bonus fclean re 

GREEN = \033[0;32m
RED = \033[0;31m
ORANGE = \033[0;33m
DEFAULT = \033[0m
YELLOW = \033[1;33m