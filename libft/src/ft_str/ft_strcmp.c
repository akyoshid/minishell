/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:43:46 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/08 20:58:58 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Compare the null-terminated strings s1 and s2 in their entirety.
// The comparison continues until the first differing character is found
// or a null character is encountered.
// If either string is not null-terminated,
// it may result in undefined behavior, including buffer overflow risks.

// === RETURN VALUES ===
// Return s1 - s2.
// If s1 and s2 are identical, return 0.
// Use unsigned characters for comparison, so that ‘\200’ is greater than ‘\0’.

// === USAGE SCENARIOS ===
// Use ft_strcmp() to check if two strings are exactly equal.

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (!(s1[i] == '\0' && s2[i] == '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str1[] = "abcd";
// 	char	str2[] = "abc";
// 	char	str3[] = "abcd";
// 	char	str4[] = "abcde";

// 	printf("%d\n", ft_strcmp(str1, str2));
// 	printf("%d\n", ft_strcmp(str1, str3));
// 	printf("%d\n", ft_strcmp(str1, str4));
// }