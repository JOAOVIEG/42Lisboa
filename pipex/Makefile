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
			$(BONUS_SRC_DIR)/here_doc_utilis.c \

OBJS := $(SRCS:.c=.o)

BONUS_OBJS := $(BONUS_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@mv ./libft/$(LIBFT) .
	cc $(CFLAGS) $(OBJS) -L. $(LIBFT) -o $(NAME)

bonus: $(LIBFT)
	@make $(BONUS_OBJS)
	@for file in $(BONUS_OBJS); do \
        if [ ! -f $(NAME) ] || [ $$file -nt $(NAME) ]; then \
        	cc $(CFLAGS) $(BONUS_OBJS) -L. $(LIBFT) -o $(NAME); \
            break; \
        fi \
    done

$(LIBFT):
	@make -C ./libft
	@mv ./libft/$(LIBFT) .

clean:
	@make clean -C ./libft
	@rm -f $(LIBFT)
	@rm -f $(BONUS_OBJS)
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean bonus fclean re