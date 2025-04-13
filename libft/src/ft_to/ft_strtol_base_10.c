/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol_base_10.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:00:00 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 22:47:57 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_set_endptr(const char *str, char **endptr)
{
	if (endptr != NULL)
		*endptr = (char *)str;
}

long	ft_strtol_base_10(const char *str, char **endptr)
{
	long	num;
	int		sign;

	if (str == NULL)
		return (_set_endptr(str, endptr), 0);
	while (ft_isspace(*str) == 1)
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1
			&& (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && *str > '7')))
			return (errno = ERANGE, _set_endptr(str, endptr), LONG_MAX);
		if (sign == -1
			&& (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && *str > '8')))
			return (errno = ERANGE, _set_endptr(str, endptr), LONG_MIN);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (_set_endptr(str, endptr), num * sign);
}
