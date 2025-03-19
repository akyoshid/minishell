/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:28:00 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:55:29 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Compare byte string s1 against byte string s2.
// Both strings are assumed to be n bytes long.

// === RETURN VALUES ===
// Return s1 - s2.
// If s1 and s2 are identical, return 0.
// Use unsigned characters for comparison, so that ‘\200’ is greater than ‘\0’.
// This behavior is not required by C
// and portable code should only depend on the sign of the returned value.

#include "../../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	str1[8] = "abcdefg\200";
// 	char	str2[8] = "abcdefg";

// 	printf("%d\n", ft_memcmp(str1, str2, 8));
// 	printf("%d\n", memcmp(str1, str2, 8));
// 	return (0);
// }
