/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:11:26 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/15 19:36:18 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <string.h>
# include <limits.h>
# include <dirent.h>
# include <termios.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line_bonus.h"

# define EXIT_USAGE			2
# define EXIT_NOTEXEC		126
# define EXIT_NOTFOUND		127

# define NO_TOKEN			-1

# define PIPE_READ			0
# define PIPE_WRITE			1

# define OPERAND_NO_LIMIT	-1

enum e_char_type
{
	CHAR_NON_METACHAR,
	CHAR_METACHAR_NON_SPACE,
	CHAR_METACHAR_SPACE,
	CHAR_NULLCHAR,
};

enum e_token_type
{
	TOKEN_WORD,
	TOKEN_REDIROP_IN,
	TOKEN_REDIROP_IN_HEREDOC,
	TOKEN_REDIROP_IN_HEREDOC_DEL_TAB,
	TOKEN_REDIROP_IN_HEREDOC_NO_EXPAND,
	TOKEN_REDIROP_IN_HEREDOC_DEL_TAB_NO_EXPAND,
	TOKEN_REDIROP_OUT,
	TOKEN_REDIROP_OUT_APPEND,
	TOKEN_CNTLOP_PIPE,
	TOKEN_CNTLOP_AND_LIST,
	TOKEN_CNTLOP_OR_LIST,
	TOKEN_CNTLOP_L_PARENTHESE,
	TOKEN_CNTLOP_R_PARENTHESE,
	TOKEN_UNDEFINED,
	TOKEN_NOOP,
	TOKEN_REDIROP_AMBIGUOUS,
};

enum e_check_syntax_return_value
{
	SYNTAX_OK,
	SYNTAX_ERROR,
};

enum e_ast_type
{
	AST_COMMAND,
	AST_PIPE,
	AST_AND,
	AST_OR,
	AST_SUBSHELL,
};

enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_OUT_APPEND,
	REDIR_AMBIGUOUS,
};

enum e_parse_command_state
{
	PARSE_COMMAND_CONTINUE,
	PARSE_COMMAND_BREAK,
};

enum e_heredoc_reader_loop_status
{
	HEREDOC_READER_LOOP_SUCCESS,
	HEREDOC_READER_LOOP_CONTINUE,
	HEREDOC_READER_LOOP_FAILURE,
};

enum e_export_type
{
	EXPORT_ASSIGN,
	EXPORT_APPEND,
};

extern volatile sig_atomic_t	g_signum;

typedef t_list					t_env_list;
typedef t_list					t_token_list;
typedef t_list					t_redir_list;

typedef struct s_ctx			t_ctx;
typedef struct s_env			t_env;
typedef struct s_token			t_token;
typedef struct s_ast			t_ast;
typedef struct s_redir			t_redir;

struct s_ctx
{
	int			exit_status;
	char		*cwd;
	t_env_list	*env_list;
	char		*sig_list[NSIG];
	bool		stop_flag;
	int			std_io_dup[3];
	bool		in_pipe_flag;
};

struct s_env
{
	char	*key;
	char	*value;
};

struct s_token
{
	int		type;
	char	*word;
};

struct s_ast
{
	int				type;
	char			**cmd_args;
	t_ast			*subshell_ast;
	t_redir_list	*redir_list;
	t_ast			*left;
	t_ast			*right;
};

struct s_redir
{
	int				type;
	char			*word;
};

typedef struct s_parse_command_info
{
	int		arg_count;
	int		arg_cap;
	bool	noop_flag;
}			t_parse_command_info;

typedef struct s_heredoc_info
{
	char	*delimiter;
	char	*tmp_file_path;
	bool	delete_tab_flag;
	bool	no_expand_flag;
	int		fd;
}			t_heredoc_info;

typedef struct s_pipe_fd_set
{
	int	current_read;
	int	current_write;
	int	next_read;
}		t_pipe_fd_set;

typedef struct s_cmd_info
{
	char	*name;
	char	**args;
	char	*usage;
	char	*valid_option_set;
	int		operand_max;
	bool	minishell_flag;
	bool	double_dash_flag;
	int		option_count;
	int		operand_count;
}			t_cmd_info;

typedef struct s_export_info
{
	char	*key;
	char	*value;
	int		type;
}			t_export_info;

// args/
// args/check_args.c
int				check_args(t_ctx *ctx, t_cmd_info *cmd_info);
// args/count_operand.c
int				count_operand(t_ctx *ctx, t_cmd_info *cmd_info);
// args/count_option.c
int				count_option(t_ctx *ctx, t_cmd_info *cmd_info);
// args/get_operand.c
char			*get_operand(t_cmd_info *cmd_info, int index);
// args/init_cmd_info.c
void			init_cmd_info1(t_cmd_info *cmd_info,
					char **cmd_args, char *usage, char *valid_option_set);
void			init_cmd_info2(t_cmd_info *cmd_info,
					int operand_max, bool minishell_flag);

// ast/
// ast/clear_ast.c
void			clear_cmd_args(char **cmd_args);
void			clear_redir_node_content(void *void_content);
void			clear_redir_list(t_redir_list **redir_list);
void			clear_ast(t_ast *ast);
// ast/get_redir_x.c
int				get_redir_type(t_redir_list *redir_node);
char			*get_redir_word(t_redir_list *redir_node);
// ast/print_ast_visual_utils.c
void			print_node_type(t_ast *ast_node);
void			print_args(t_ast *ast_node, const char *prefix);
void			print_redir_one(t_redir_list *redir, const char *prefix);
void			print_redirections(t_ast *ast_node, const char *prefix);
// ast/print_ast_visual.c
void			print_ast_visual(t_ast *ast);
// ast/print_ast.c
void			print_ast(t_ast *ast);

// builtin
// builtin/cd_utils.c
int				w_chdir(t_ctx *ctx, char *path);
void			update_wd_data(t_ctx *ctx, char *path);
// builtin/cd.c
void			cd_builtin(t_ctx *ctx, char **cmd_args);
// builtin/echo.c
void			echo_builtin(t_ctx *ctx, char **cmd_args);
// builtin/env.c
void			env_builtin(t_ctx *ctx, char **cmd_args);
// builtin/exit_atol.c
long			exit_atol(t_ctx *ctx, char *str, bool *fin_flag);
// builtin/exit.c
void			exit_builtin(t_ctx *ctx, char **cmd_args);
// builtin/export_no_operand.c
void			export_no_operand(t_ctx *ctx);
// builtin/export_with_operand.c
int				export_with_operand(t_ctx *ctx, t_cmd_info *cmd_info);
// builtin/export.c
void			export_builtin(t_ctx *ctx, char **cmd_args);
// builtin/pwd.c
void			pwd_builtin(t_ctx *ctx, char **cmd_args);
// builtin/unset.c
void			unset_builtin(t_ctx *ctx, char **cmd_args);

// env/
// env/clear_env_x.c
void			clear_env_node_value(void *void_content);
void			clear_env_node_content(void *void_content);
void			clear_env_list(t_env_list **env_list);
// env/create_env_x.c
t_env_list		*create_env_node(char *key, char *value);
t_env_list		*create_env_list(char **envp);
// env/create_envp.c
char			**create_envp(t_ctx *ctx);
// env/delete_env_node.c
void			delete_env_node(t_env_list **env_list, t_env_list *target_node);
// env/dup_env_list.c
t_env_list		*dup_env_list(t_env_list *env_list);
// env/get_env_x.c
char			*get_env_key(t_env_list *env_node);
char			*get_env_value(t_env_list *env_node);
// env/init_env_list.c
void			init_env_list(char **envp, t_ctx *ctx);
// env/print_env_list.c
void			print_env_list(t_env_list *env_list);
// env/search_env_x.c
char			*search_env_value(t_ctx *ctx, t_env_list *env_list, char *key);
t_env_list		*search_env_node(t_env_list *env_list, char *key);
t_env_list		*search_prev_env_node(
					t_env_list *env_list, t_env_list *current_node);
// env/set_env_x.c
void			set_env_value(t_env_list *env_node, char *value);
// env/sort_env_list.c
t_env_list		*sort_env_list(t_env_list *env_list);
// env/update_env_node.c
void			update_env_node(t_env_list **env_list,
					char *key, char *value, bool append_flag);

// exec/
// exec/exec_and_or.c
void			exec_and_or(t_ctx *ctx, t_ast *ast_node);
// exec/exec_ast.c
void			exec_ast(t_ctx *ctx, t_ast *ast_node);
// exec/exec_builtin_command.c
int				check_cmd_is_builtin(char *cmd);
void			exec_builtin_command(t_ctx *ctx, t_ast *ast_node);
// exec/exec_command_in_pipe.c
pid_t			exec_command_in_pipe(
					t_ctx *ctx, t_ast *ast_node, t_pipe_fd_set *pipe_fd_set);
// exec/exec_command.c
void			exec_command(t_ctx *ctx, t_ast *ast_node);
// exec/exec_external_command.c
void			wait_child(t_ctx *ctx, pid_t pid);
void			exec_external_command(t_ctx *ctx, t_ast *ast_node);
void			exec_external_command_in_pipe(t_ctx *ctx, t_ast *ast_node);
// exec/exec_pipe.c
void			exec_pipe(t_ctx *ctx, t_ast *ast_node);
// exec/exec_subshell.c
void			exec_subshell(t_ctx *ctx, t_ast *ast_node);
// exec/get_path.c
char			*get_path(t_ctx *ctx, char *cmd);
// exec/wait_child.c
void			wait_child(t_ctx *ctx, pid_t last_pid);

// expansion/env
// expansion/env/expand_env_in_token_list.c
void			expand_env_in_token_list(
					t_ctx *ctx, t_token_list **token_list_p);
// expansion/env/expand_env.c
void			expand_env_core(t_ctx *ctx, char **word_p, int *i_p);
void			expand_env(t_ctx *ctx, char **word_p);
// expansion/env/handle_new_list_is_null.c
t_token_list	*handle_new_list_is_null(
					t_token_list *prev_node, t_token_list *current_node,
					char *current_node_word_original);
// expansion/env/handle_prev_node_is_redirop.c
t_token_list	*handle_prev_node_is_redirop(
					t_token_list *prev_node, t_token_list *current_node,
					char *current_node_word_original, t_token_list *new_list);
// expansion/env/is_avail_char_for_var_name.c
int				is_avail_char_for_var_name(int c);
// expansion/env/split_word.c
t_token_list	*split_word(t_token_list **token_list_p,
					t_token_list *prev_node, t_token_list *current_node,
					char *current_node_word_original);
// expansion/wildcard
// expansion/wildcard/expand_wildcard_in_token_list.c
void			expand_wildcard_in_token_list(t_token_list **token_list_p);
// expansion/wildcard/get_matched_files.c
char			**get_matched_files(char *pattern, int *count_p);
// expansion/wildcard/has_wildcard.c
bool			has_wildcard(char *str);
// expansion/wildcard/is_pattern_matched.c
bool			is_pattern_matched(char *pattern, char *file);
// expansion
// expansion/perform_expansion.c
void			perform_expansion(t_ctx *ctx, t_token_list **token_list_p);
// expansion/remove_quote.c
void			remove_quote(t_token_list *token_list);

// fcntl
// fcntl/is_directory.c
int				is_directory(char *path);
// fcntl/manage_pipe_fd.c
void			init_pipe_fd_set(t_pipe_fd_set *pipe_fd_set);
t_pipe_fd_set	*update_pipe_fd_set(t_pipe_fd_set *pipe_fd_set, int pipe_fd[2]);
void			close_pipe_fd(int pipe_fd);
void			close_current_pipe_fd_set(t_pipe_fd_set *pipe_fd_set);
void			close_pipe_fd_set(t_pipe_fd_set *pipe_fd_set);
// fcntl/manage_std_io.c
void			init_std_io_dup(t_ctx *ctx);
void			close_std_io_dup(t_ctx *ctx);
void			dup_std_io(t_ctx *ctx);
void			restore_std_io(t_ctx *ctx);
// fcntl/setup_pipe.c
int				setup_pipe(t_pipe_fd_set *pipe_fd_set);
// fcntl/setup_redir.c
int				setup_redir(t_ctx *ctx, t_redir_list *redir_list);
// fcntl/w_close.c
int				w_close(int fd);
// fcntl/w_dup2.c
int				w_dup2(int oldfd, int newfd);

// heredoc/
// heredoc/cmp_delimiter.c
int				cmp_delimiter(char *delimiter, char *new_line);
// heredoc/delete_tab.c
void			delete_tab(char *new_line);
// heredoc/expand_env_heredoc.c
void			expand_env_heredoc(t_ctx *ctx, char **new_line_p);
// heredoc/get_heredoc_path.c
char			*get_heredoc_path(void);
// heredoc/perform_heredoc.c
int				perform_heredoc(t_ctx *ctx, t_redir *content,
					int token_type, t_token_list **current_token_node_p);

// parse/
// parse/parse_and_or.c
t_ast			*parse_and_or(t_ctx *ctx, t_token_list **current_token_node_p);
// parse/parse_command.c
t_ast			*parse_command(t_ctx *ctx, t_token_list **current_token_node_p);
// parse/parse_pipe.c
t_ast			*parse_pipe(t_ctx *ctx, t_token_list **current_token_node_p);
t_redir_list	*parse_redir(
					t_ctx *ctx, t_token_list **current_token_node_p);
// parse/parse_subshell.c
t_ast			*parse_subshell(
					t_ctx *ctx, t_token_list **current_token_node_p);
// parse/parse_token_list_into_ast.c
t_ast			*parse_token_list_into_ast(
					t_ctx *ctx, t_token_list *token_list);

// reader/
// reader/is_empty_input.c
int				is_empty_input(char *input);
// reader/reader_loop.c
void			reader_loop(t_ctx *ctx);
// reader/update_history.c
void			update_history(char **input_p, char **prev_input_p);

// signal
// signal/check_g_signum_in_heredoc.c
int				check_g_signum_in_heredoc(void);
// signal/check_g_signum.c
int				check_g_signum(void);
// signal/handle_sigint_in_heredoc.c
int				handle_sigint_in_heredoc(t_ctx *ctx,
					t_token_list **current_token_node_p, char *input);
// signal/trap_signal.c
void			trap_signal_in_rl(t_ctx *ctx);
void			trap_signal_out_of_rl(t_ctx *ctx);
void			reset_signal_handler(void);
// signal/init_sig_list.c
void			init_sig_list(t_ctx *ctx);

// syntax/
// syntax/current_is_head.c
int				check_syntax_current_is_head(int head_token_type);
// syntax/prev_is_cntlop_pipe_and_or_list_l_parenthese.c
int				check_syntax_prev_is_cntlop_pipe_and_or_list_l_parenthese(
					int current_token_type);
// syntax/prev_is_cntlop_r_parenthese.c
int				check_syntax_prev_is_cntlop_r_parenthese(
					int current_token_type, t_token_list *current_token_node);
// syntax/prev_is_redirop.c
int				check_syntax_prev_is_redirop(int current_token_type);
// syntax/prev_is_word.c
int				check_syntax_prev_is_word(int current_token_type);
// syntax/check_syntax.c
int				check_syntax(t_token_list *token_list);
// syntax/print_syntax_error.c
void			print_syntax_error(int current_token_type, char *token_word);

// token/
// token/clear_token_x.c
void			clear_token_node_content(void *void_content);
void			clear_token_node(t_token_list *token_node);
void			clear_token_list(t_token_list **token_list);
// token/count_token_node.c
int				count_token_node(t_token_list *token_list);
// token/create_op_token_node.c
t_token_list	*create_op_token_node(char **input_p);
// token/create_token_list.c
t_token_list	*create_token_list(char *input);
// token/create_word_token_node.c
t_token_list	*create_word_token_node(char **input_p);
// token/get_char_type.c
int				get_char_type(char c);
// token/get_token_x.c
int				get_token_type(t_token_list *token_node);
char			*get_token_word(t_token_list *token_node);
// token/print_token_list.c
void			print_token_list(t_token_list *token_list);
// token/set_token_x.c
void			set_token_type(t_token_list *token_node, int type);
void			set_token_word(t_token_list *token_node, char *word);

// utils/
// utils/free_2d_array.c
void			free_2d_array(char **ptr);
// utils/ft_xcalloc.c
void			*ft_xcalloc(size_t count, size_t size);
// utils/ft_xitoa.c
char			*ft_xitoa(int n);
// utils/ft_xlstnew.c
t_list			*ft_xlstnew(void *content);
// utils/ft_xltoa.c
char			*ft_xltoa(long n);
// utils/ft_xrealloc.c
void			*ft_xrealloc(void *ptr, size_t old_size, size_t new_size);
// utils/ft_xsplit.c
char			**ft_xsplit(char const *s, char c);
// utils/ft_xstrdup.c
char			*ft_xstrdup(const char *s1);
// utils/ft_xstrjoin.c
char			*ft_xstrjoin(char const *s1, char const *s2);
// utils/ft_xstrjoin3.c
char			*ft_xstrjoin3(char const *s1, char const *s2, char const *s3);
// utils/ft_xstrndup.c
char			*ft_xstrndup(const char *s1, size_t n);
// utils/ft_xstrtrim.c
char			*ft_xstrtrim(const char *s1, const char *set);
// utils/is_ifs.c
int				is_ifs(char c);
// utils/print_error.c
void			print_error(char *mes1, char *mes2, char *mes3, bool use_errno);
// utils/xmalloc.c
void			*xmalloc(size_t size);

#endif
