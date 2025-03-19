/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:51:09 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 18:00:29 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Convert the initial portion of the string pointed to by str to int.
// It is equivalent to: (int)strtol(str, (char **)NULL, 10);

// === STRTOL DESCRIPTION===
// The strtol() function converts the string in str to a long value.
// The string may begin with some white spaces(as determined by isspace(3))
// followed by a single optional '+' or '-' sign
// Conversion will stop at the first character which is not a valid digit.

// === STRTOL RETURN VALUES ===
// Return the conversion result, unless the value would underflow or overflow.
// If no conversion could be performed, 0 is returned.
// If an overflow occurs, LONG_MAX is returned.
// If an underflow occurs, LONG_MIN is returned.

// === ISSPACE ===
// '\t', '\n', '\v', '\f', '\r', & ' ' are space!

#include "../../inc/libft.h"

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
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
			&& (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && *str >= '7')))
			return ((int)LONG_MAX);
		if (sign == -1
			&& (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && *str >= '8')))
			return ((int)LONG_MIN);
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)num * sign);
}

// int	main(void)
// {
// 	char	str[] = "\t 1234abc567";
// 	// char	str[] = "\t +4294967294abc567";
// 	// char	str[] = "\t -9223372036854775808abc567";

// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	return (0);
// }
