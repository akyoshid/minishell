NAME =		minishell

INC_DIR =	inc/
SRC_DIR =	src/
OBJ_DIR =	obj/
LIBFT_DIR =	libft/

INC =				$(INC_DIR)minishell.h

SRC = \
					$(SRC_DIR)args/check_args.c \
					$(SRC_DIR)args/count_operand.c \
					$(SRC_DIR)args/count_option.c \
					$(SRC_DIR)args/get_operand.c \
					$(SRC_DIR)args/init_cmd_info.c \
					$(SRC_DIR)ast/clear_ast.c \
					$(SRC_DIR)ast/get_redir_x.c \
					$(SRC_DIR)ast/print_ast_visual_utils.c \
					$(SRC_DIR)ast/print_ast_visual.c \
					$(SRC_DIR)ast/print_ast.c \
					$(SRC_DIR)builtin/echo.c \
					$(SRC_DIR)builtin/cd_utils.c \
					$(SRC_DIR)builtin/cd.c \
					$(SRC_DIR)builtin/env.c \
					$(SRC_DIR)builtin/exit_atol.c \
					$(SRC_DIR)builtin/exit.c \
					$(SRC_DIR)builtin/export_no_operand.c \
					$(SRC_DIR)builtin/export_with_operand.c \
					$(SRC_DIR)builtin/export.c \
					$(SRC_DIR)builtin/pwd.c \
					$(SRC_DIR)builtin/unset.c \
					$(SRC_DIR)env/clear_env_x.c \
					$(SRC_DIR)env/create_env_x.c \
					$(SRC_DIR)env/create_envp.c \
					$(SRC_DIR)env/delete_env_node.c \
					$(SRC_DIR)env/dup_env_list.c \
					$(SRC_DIR)env/get_env_x.c \
					$(SRC_DIR)env/init_env_list.c \
					$(SRC_DIR)env/print_env_list.c \
					$(SRC_DIR)env/search_env_x.c \
					$(SRC_DIR)env/set_env_x.c \
					$(SRC_DIR)env/sort_env_list.c \
					$(SRC_DIR)env/update_env_node.c \
					$(SRC_DIR)exec/exec_and_or.c \
					$(SRC_DIR)exec/exec_ast.c \
					$(SRC_DIR)exec/exec_builtin_command.c \
					$(SRC_DIR)exec/exec_command_in_pipe.c \
					$(SRC_DIR)exec/exec_command.c \
					$(SRC_DIR)exec/exec_external_command.c \
					$(SRC_DIR)exec/exec_pipe.c \
					$(SRC_DIR)exec/exec_subshell.c \
					$(SRC_DIR)exec/get_path.c \
					$(SRC_DIR)exec/wait_child.c \
					$(SRC_DIR)expansion/expand_env_in_token_list.c \
					$(SRC_DIR)expansion/expand_env.c \
					$(SRC_DIR)expansion/handle_new_list_is_null.c \
					$(SRC_DIR)expansion/handle_prev_node_is_redirop.c \
					$(SRC_DIR)expansion/is_avail_char_for_var_name.c \
					$(SRC_DIR)expansion/perform_expansion.c \
					$(SRC_DIR)expansion/remove_quote.c \
					$(SRC_DIR)expansion/split_word.c \
					$(SRC_DIR)fcntl/is_directory.c \
					$(SRC_DIR)fcntl/manage_pipe_fd.c \
					$(SRC_DIR)fcntl/manage_std_io.c \
					$(SRC_DIR)fcntl/setup_pipe.c \
					$(SRC_DIR)fcntl/setup_redir.c \
					$(SRC_DIR)fcntl/w_close.c \
					$(SRC_DIR)fcntl/w_dup2.c \
					$(SRC_DIR)heredoc/cmp_delimiter.c \
					$(SRC_DIR)heredoc/delete_tab.c \
					$(SRC_DIR)heredoc/expand_env_heredoc.c \
					$(SRC_DIR)heredoc/get_heredoc_path.c \
					$(SRC_DIR)heredoc/perform_heredoc.c \
					$(SRC_DIR)parse/parse_and_or.c \
					$(SRC_DIR)parse/parse_command.c \
					$(SRC_DIR)parse/parse_pipe.c \
					$(SRC_DIR)parse/parse_redir.c \
					$(SRC_DIR)parse/parse_subshell.c \
					$(SRC_DIR)parse/parse_token_list_into_ast.c \
					$(SRC_DIR)reader/is_empty_input.c \
					$(SRC_DIR)reader/reader_loop.c \
					$(SRC_DIR)reader/update_history.c \
					$(SRC_DIR)signal/check_g_signum_in_heredoc.c \
					$(SRC_DIR)signal/check_g_signum.c \
					$(SRC_DIR)signal/handle_signal_in_heredoc.c \
					$(SRC_DIR)signal/handle_signal.c \
					$(SRC_DIR)signal/init_sig_list.c \
					$(SRC_DIR)syntax/check_syntax.c \
					$(SRC_DIR)syntax/current_is_head.c \
					$(SRC_DIR)syntax/prev_is_cntlop_pipe_and_or_list_l_parenthese.c \
					$(SRC_DIR)syntax/prev_is_cntlop_r_parenthese.c \
					$(SRC_DIR)syntax/prev_is_redirop.c \
					$(SRC_DIR)syntax/prev_is_word.c \
					$(SRC_DIR)syntax/print_syntax_error.c \
					$(SRC_DIR)token/clear_token_x.c \
					$(SRC_DIR)token/count_token_node.c \
					$(SRC_DIR)token/create_op_token_node.c \
					$(SRC_DIR)token/create_token_list.c \
					$(SRC_DIR)token/create_word_token_node.c \
					$(SRC_DIR)token/get_char_type.c \
					$(SRC_DIR)token/get_token_x.c \
					$(SRC_DIR)token/print_token_list.c \
					$(SRC_DIR)token/set_token_x.c \
					$(SRC_DIR)utils/free_2d_array.c \
					$(SRC_DIR)utils/ft_xcalloc.c \
					$(SRC_DIR)utils/ft_xitoa.c \
					$(SRC_DIR)utils/ft_xlstnew.c \
					$(SRC_DIR)utils/ft_xltoa.c \
					$(SRC_DIR)utils/ft_xrealloc.c \
					$(SRC_DIR)utils/ft_xsplit.c \
					$(SRC_DIR)utils/ft_xstrdup.c \
					$(SRC_DIR)utils/ft_xstrjoin.c \
					$(SRC_DIR)utils/ft_xstrjoin3.c \
					$(SRC_DIR)utils/ft_xstrndup.c \
					$(SRC_DIR)utils/ft_xstrtrim.c \
					$(SRC_DIR)utils/is_ifs.c \
					$(SRC_DIR)utils/print_error.c \
					$(SRC_DIR)utils/xmalloc.c \
					$(SRC_DIR)main.c

OBJ =				$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
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
	valgrind --leak-check=full --leak-check=full \
	--show-leak-kinds=definite,indirect,possible \
	--track-fds=yes \
	--suppressions=valgrind.supp ./minishell

.PHONY: all clean fclean re bonus val
