/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:31:07 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/08 20:57:20 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Compare the null-terminated strings s1 and s2 up to n characters.
// The comparison stops when n characters have been compared,
//  a null character is encountered, or a difference is found.
// If both strings are shorter than n characters,
//  the comparison is limited to their lengths.

// === RETURN VALUES ===
// Return s1 - s2 for up to the first n characters.
// If the first n characters of s1 and s2 are identical, return 0.
// Use unsigned characters for comparison, so that ‘\200’ is greater than ‘\0’.

// === USAGE SCENARIOS ===
// Use strncmp when comparing only the initial part of two strings
//  or when limiting comparisons to a specific number of characters
//  to reduce the risk of buffer overflow.

#include "../../inc/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		if (str1[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	str1[] = "abc\200";
// 	char	str2[] = "abc";

// 	printf("%d\n", ft_strncmp(str1, str2, 5));
// 	printf("%d\n", strncmp(str1, str2, 5));
// 	return (0);
// }
