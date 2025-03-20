NAME =		minishell

INC_DIR =	inc/
SRC_DIR =	src/
OBJ_DIR =	obj/
LIBFT_DIR =	libft/

INC =				$(INC_DIR)minishell.h

SRC = \
					$(SRC_DIR)env/clear_env_x.c \
					$(SRC_DIR)env/create_env_x.c \
					$(SRC_DIR)env/get_env_x.c \
					$(SRC_DIR)env/init_env_list.c \
					$(SRC_DIR)env/print_env_list.c \
					$(SRC_DIR)env/search_env_x.c \
					$(SRC_DIR)utils/ft_xlstnew.c \
					$(SRC_DIR)utils/ft_xstrdup.c \
					$(SRC_DIR)utils/ft_xstrndup.c \
					$(SRC_DIR)utils/xmalloc.c \
					$(SRC_DIR)main.c

OBJ =				$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_LIB = -L ./libft -lft -lreadline

RM = rm -f
AR = ar rcs

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) -I$(INC_DIR) -o $@ $(LIBFT_LIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

val:
	valgrind --leak-check=full --suppressions=valgrind.supp ./minishell

.PHONY: all clean fclean re bonus val
