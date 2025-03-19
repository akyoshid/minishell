/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:23:58 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/23 02:35:21 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_print_hex_char(int fd, char const num, int is_upper, int *const cp)
{
	char	c;

	if (num < 10)
	{
		c = '0' + num;
		ft_print_char(fd, c, cp);
	}
	else
	{
		if (is_upper == 1)
			c = 'A' + num - 10;
		else
			c = 'a' + num - 10;
		ft_print_char(fd, c, cp);
	}
}

void	ft_print_hex(
			int fd, unsigned long long num, int is_upper, int *const cp)
{
	char	remainder;

	remainder = num % 16;
	if (num / 16 > 0)
		ft_print_hex(fd, num / 16, is_upper, cp);
	if (*cp != -1)
		ft_print_hex_char(fd, remainder, is_upper, cp);
}

void	ft_print_ptr(int fd, void *ptr, int *const cp)
{
	if (ptr == NULL)
	{
		ft_print_str(fd, "(nil)", cp);
		return ;
	}
	ft_print_str(fd, "0x", cp);
	if (*cp != -1)
		ft_print_hex(fd, (unsigned long long)ptr, 0, cp);
}
