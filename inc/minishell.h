/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:11:26 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/19 13:57:54 by akyoshid         ###   ########.fr       */
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

// utils/
// utils/ft_xlstnew.c
t_list	*ft_xlstnew(void *content);
// utils/ft_xstrdup.c
char	*ft_xstrdup(const char *s1);
// utils/ft_xstrndup.c
char	*ft_xstrndup(const char *s1, size_t n);
// utils/xmalloc.c
void	*xmalloc(size_t size);

#endif
