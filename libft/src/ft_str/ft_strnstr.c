/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:38:08 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:59:41 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Locates the first occurrence of the string needle in the string haystack,
// where not more than len characters are searched.
// Characters that appear after a ‘\0’ character are not searched.

// === RETURN VALUES ===
// If needle is an empty string, haystack is returned;
// if needle occurs nowhere in haystack, NULL is returned;
// otherwise a pointer to the first occurrence of the needle is returned.

// === CAUTION ===
// strnstr(NULL, "42", 0)) will not cause a segfault
// because more than len characters are not searched.

#include "../../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (i + j < len && haystack[i + j] != '\0'
			&& haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	// char	str1[] = "abcdefg";
// 	// char	str2[] = "def";
// 	// char	str3[] = "abbbcdefg";

// 	printf("%p\n", (void *)ft_strnstr(str1, str2, 6));
// 	printf("%p\n", (void *)strnstr(str1, str2, 6));
// 	// printf("%p\n", (void *)ft_strnstr(str1, str2, 5));
// 	// printf("%p\n", (void *)strnstr(str1, str2, 5));
// 	// printf("%p\n", (void *)ft_strnstr(NULL, str2, 5));
// 	// printf("%p\n", (void *)strnstr(NULL, str2, 5));
// 	// printf("%p\n", (void *)ft_strnstr(str1, NULL, 5));
// 	// printf("%p\n", (void *)strnstr(str1, NULL, 5));
// 	// printf("%p\n", (void *)ft_strnstr(str1, str2, 0));
// 	// printf("%p\n", (void *)strnstr(str1, str2, 0));
// 	// printf("%p\n", (void *)ft_strnstr(NULL, "42", 0));
// 	// printf("%p\n", (void *)strnstr(NULL, "42", 0));
// 	// printf("%p\n", (void *)ft_strnstr(str3, "42", 20));
// 	// printf("%p\n", (void *)strnstr(str3, "42", 20));
// 	// printf("%p\n", (void *)ft_strnstr("", "42", 2));
// 	// printf("%p\n", (void *)strnstr("", "42", 2));
// 	// printf("%p\n", (void *)ft_strnstr("", "42", -1));
// 	// printf("%p\n", (void *)strnstr("", "42", -1));
// 	return (0);
// }
