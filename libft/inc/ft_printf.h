/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:24:02 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/07 05:23:43 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

void	ft_print_char(int fd, char const c, int *const cp);
void	ft_print_str(int fd, char const *str, int *const cp);
void	ft_print_signed_dec(int fd, int num, int *const cp);
void	ft_print_unsigned_dec(int fd, unsigned int num, int *const cp);
void	ft_print_hex_char(int fd, char const num, int is_upper, int *const cp);
void	ft_print_hex(
			int fd, unsigned long long num, int is_upper, int *const cp);
void	ft_print_ptr(int fd, void *ptr, int *const cp);
void	ft_print_varg(int fd, char const fmt, va_list *app, int *const cp);
int		ft_printf(const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);

#endif
