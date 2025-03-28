/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:11:26 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/27 13:29:15 by akyoshid         ###   ########.fr       */
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

# define EXIT_USAGE		2
# define EXIT_NOTEXEC	126
# define EX_NOTFOUND	127
# define NO_TOKEN		-1

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
	TOKEN_REDIROP_OUT,
	TOKEN_REDIROP_OUT_APPEND,
	TOKEN_CNTLOP_PIPE,
	TOKEN_CNTLOP_AND_LIST,
	TOKEN_CNTLOP_OR_LIST,
	TOKEN_CNTLOP_L_PARENTHESE,
	TOKEN_CNTLOP_R_PARENTHESE,
	TOKEN_UNDEFINED,
	TOKEN_NOOP,
};

enum e_check_syntax_return_value
{
	SYNTAX_OK,
	SYNTAX_ERROR,
};

typedef t_list			t_env_list;
typedef t_list			t_token_list;
typedef struct s_ctx	t_ctx;
typedef struct s_env	t_env;
typedef struct s_token	t_token;

struct s_ctx
{
	t_env_list	*env_list;
	int			exit_status;
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

// env/
// env/clear_env_x.c
void			clear_env_node_content(void *void_content);
void			clear_env_list(t_env_list **env_list);
// env/create_env_x.c
t_env_list		*create_env_node(char *key, char *value);
t_env_list		*create_env_list(char **envp);
// env/get_env_x.c
char			*get_env_key(t_env_list *env_node);
char			*get_env_value(t_env_list *env_node);
// env/init_env_list.c
void			init_env_list(char **envp, t_ctx *ctx);
// env/print_env_list.c
void			print_env_list(t_env_list *env_list);
// env/search_env_x.c
char			*search_env_value(t_env_list *env_list, char *key);
t_env_list		*search_env_node(t_env_list *env_list, char *key);

// expansion
// expansion/expand_env_in_token_list.c
void			expand_env_in_token_list(
					t_ctx *ctx, t_token_list **token_list_p);
// expansion/expand_env.c
void			expand_env(t_ctx *ctx, char **word_p);
// expansion/is_avail_char_for_var_name.c
int				is_avail_char_for_var_name(int c);
// expansion/perform_expansion.c
void			perform_expansion(t_ctx *ctx, t_token_list **token_list_p);
// expansion/remove_quote.c
void			remove_quote(t_token_list *token_list);
// expansion/split_word.c
t_token_list	*split_word(t_token_list **token_list_p,
					t_token_list *prev_node, t_token_list *current_node);

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
// utils/ft_xlstnew.c
t_list			*ft_xlstnew(void *content);
// utils/ft_xstrdup.c
char			*ft_xstrdup(const char *s1);
// utils/ft_xstrjoin.c
char			*ft_xstrjoin(char const *s1, char const *s2);
// utils/ft_xstrndup.c
char			*ft_xstrndup(const char *s1, size_t n);
// utils/ft_xstrtrim.c
char			*ft_xstrtrim(const char *s1, const char *set);
// utils/is_ifs.c
int				is_ifs(char c);
// utils/xmalloc.c
void			*xmalloc(size_t size);

#endif
