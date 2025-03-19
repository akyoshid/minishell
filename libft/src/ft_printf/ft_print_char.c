/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:21:51 by akyoshid          #+#    #+#             */
/*   Updated: 2024/12/23 00:34:40 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_print_char(int fd, char const c, int *const cp)
{
	if ((write(fd, &c, 1)) == -1)
		*cp = -1;
	else
		(*cp)++;
}

void	ft_print_str(int fd, char const *str, int *const cp)
{
	if (str == NULL)
	{
		ft_print_str(fd, "(null)", cp);
		return ;
	}
	while (*str != '\0')
	{
		ft_print_char(fd, *str, cp);
		if (*cp == -1)
			return ;
		str++;
	}
}
