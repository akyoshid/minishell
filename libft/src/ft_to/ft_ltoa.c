/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:33:49 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 23:47:00 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Allocates & returns a string representing the integer.
// Negative numbers must be handled.

#include "../../inc/libft.h"

static int	ft_countdigit(long n)
{
	int	digit;

	digit = 0;
	if (n < 0)
	{
		digit++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static char	*ft_storenum(char *dst, long n, int digit)
{
	if (n < 0)
	{
		dst[0] = '-';
		n *= -1;
	}
	dst[digit] = '\0';
	digit--;
	while (n > 0)
	{
		dst[digit] = (n % 10) + '0';
		n /= 10;
		digit--;
	}
	return (dst);
}

char	*ft_ltoa(long n)
{
	char	*buff;
	int		digit;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
	digit = ft_countdigit(n);
	buff = malloc((digit + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	return (ft_storenum(buff, n, digit));
}
