/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:11:26 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/21 14:52:34 by akyoshid         ###   ########.fr       */
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

# define EXIT_USAGE 2
# define EXIT_NOTEXEC	126
# define EX_NOTFOUND	127

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

// token/
// token/clear_token_x.c
void			clear_token_node_content(void *void_content);
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
// utils/xmalloc.c
void			*xmalloc(size_t size);

#endif
