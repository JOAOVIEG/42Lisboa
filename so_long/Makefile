NAME = so_long
SRC_DIR = src
OBJ_DIR = .objs
LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = libs/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
GET_NEXT_LINE_DIR = libs/get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/libftgetnextline.a

SRC = $(addprefix $(SRC_DIR)/, main.c game_build.c read_map.c error_msg.c map_checks.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CC = cc
HEAD = -I./inc -I./$(LIBFT_DIR) -I./$(FT_PRINTF_DIR) -I./$(GET_NEXT_LINE_DIR)
CFLAGS = -Wall -Werror -Wextra -g
LFLAGS = -L $(LIBFT_DIR) -lft -L $(FT_PRINTF_DIR) -lftprintf -L $(GET_NEXT_LINE_DIR) -lftgetnextline
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE)
	$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(OBJ_DIR)/%.o: $(GET_NEXT_LINE_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(OBJ_DIR)/%.o:$(FT_PRINTF_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(GET_NEXT_LINE):
	make -C $(GET_NEXT_LINE_DIR)

$(SRC_DIR):
	make -C $(SRC_DIR)

debug: $(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE)
	$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)
	ASAN_OPTIONS=halt_on_error=1 lldb $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)
	make clean -C $(GET_NEXT_LINE_DIR)
	$(RM) $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)
	make fclean -C $(GET_NEXT_LINE_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re