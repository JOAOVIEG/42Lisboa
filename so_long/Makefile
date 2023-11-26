NAME        := so_long
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 

SRCS        :=      src/game_build.c \
                          src/checks_utilis2.c \
                          src/map_checks.c \
                          src/read_map.c \
                          src/checks_utilis.c \
                          src/checks_utilis1.c \
                          src/main.c \
                          src/error_msg.c \
						  src/game_loop.c \
                          src/game_loop1.c \
                          src/game_loop2.c \
                          libs/get_next_line/get_next_line.c \
                          libs/get_next_line/get_next_line_utils.c \
                          libs/ft_printf/ft_printf.c \
                          libs/ft_printf/print_functions.c \
                          libs/libft/ft_lstmap.c \
                          libs/libft/ft_memset.c \
                          libs/libft/ft_split.c \
                          libs/libft/ft_strtrim.c \
                          libs/libft/ft_isprint.c \
                          libs/libft/ft_strlen.c \
                          libs/libft/ft_putstr_fd.c \
                          libs/libft/ft_putendl_fd.c \
                          libs/libft/ft_substr.c \
                          libs/libft/ft_toupper.c \
                          libs/libft/ft_tolower.c \
                          libs/libft/ft_lstadd_back.c \
                          libs/libft/ft_striteri.c \
                          libs/libft/ft_isdigit.c \
                          libs/libft/ft_putnbr_fd.c \
                          libs/libft/ft_itoa.c \
                          libs/libft/ft_strlcat.c \
                          libs/libft/ft_memmove.c \
                          libs/libft/ft_strncmp.c \
                          libs/libft/ft_strdup.c \
                          libs/libft/ft_lstlast.c \
                          libs/libft/ft_isalpha.c \
                          libs/libft/ft_lstdelone.c \
                          libs/libft/ft_strcmp.c \
                          libs/libft/ft_calloc.c \
                          libs/libft/ft_memchr.c \
                          libs/libft/ft_lstadd_front.c \
                          libs/libft/ft_strchr.c \
                          libs/libft/ft_strnstr.c \
                          libs/libft/ft_isalnum.c \
                          libs/libft/ft_lstclear.c \
                          libs/libft/ft_memcpy.c \
                          libs/libft/ft_memcmp.c \
                          libs/libft/ft_atoi.c \
                          libs/libft/ft_putchar_fd.c \
                          libs/libft/ft_strrchr.c \
                          libs/libft/ft_lstiter.c \
                          libs/libft/ft_realloc.c \
                          libs/libft/ft_isascii.c \
                          libs/libft/ft_strjoin.c \
                          libs/libft/ft_strlcpy.c \
                          libs/libft/ft_strmapi.c \
                          libs/libft/ft_lstsize.c \
                          libs/libft/ft_lstnew.c \
                          libs/libft/ft_bzero.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

$(NAME): ${OBJS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "$(GREEN)$(NAME) created[0m ✔️"
            
all:		${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C mlx_linux clean 
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re
