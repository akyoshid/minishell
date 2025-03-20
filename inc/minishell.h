/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:11:26 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/20 14:26:22 by akyoshid         ###   ########.fr       */
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

typedef t_list			t_env_list;
typedef struct s_ctx	t_ctx;
typedef struct s_env	t_env;

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

// env/
// env/clear_env_x.c
void		clear_env_node_content(void *void_content);
void		clear_env_list(t_env_list **env_list);
// env/create_env_x.c
t_env_list	*create_env_node(char *key, char *value);
t_env_list	*create_env_list(char **envp);
// env/get_env_x.c
char		*get_env_key(t_env_list *env_node);
char		*get_env_value(t_env_list *env_node);
// env/init_env_list.c
void		init_env_list(char **envp, t_ctx *ctx);
// env/print_env_list.c
void		print_env_list(t_env_list *env_list);
// env/search_env_x.c
char		*search_env_value(t_env_list *env_list, char *key);
t_env_list	*search_env_node(t_env_list *env_list, char *key);

// utils/
// utils/ft_xlstnew.c
t_list		*ft_xlstnew(void *content);
// utils/ft_xstrdup.c
char		*ft_xstrdup(const char *s1);
// utils/ft_xstrndup.c
char		*ft_xstrndup(const char *s1, size_t n);
// utils/ft_xstrtrim.c
char		*ft_xstrtrim(const char *s1, const char *set);
// utils/xmalloc.c
void		*xmalloc(size_t size);

#endif
