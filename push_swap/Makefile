NAME = push_swap
SRC_DIR = src
ACT_DIR = actions
OBJ_DIR = .objs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/stack_utilis.c \
      $(SRC_DIR)/$(ACT_DIR)/actions.c \
      $(SRC_DIR)/$(ACT_DIR)/actions1.c \
	  $(SRC_DIR)/$(ACT_DIR)/actions2.c \
      $(SRC_DIR)/$(ACT_DIR)/actions_utilis.c

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CC = clang
HEAD = -I./inc -I./$(LIBFT_DIR)
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
LFLAGS = -L ./$(LIBFT_DIR) -lft
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@ -MMD -MP

$(LIBFT):
		@make -C $(LIBFT_DIR)

clean:
		@make clean -C $(LIBFT_DIR)
		@$(RM) $(OBJ_DIR)

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g -O0
debug: all

.PHONY: all clean fclean re debug

-include $(OBJ:.o=.d)