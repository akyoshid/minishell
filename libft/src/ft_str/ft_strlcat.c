/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:16:48 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:59:15 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === BEHAVIOR ===
// Append string src to the end of dst.
// Append at most dstsize - strlen(dst) - 1 characters. 
// Always be NULL-terminate.

// === RETURN VALUE ===
// Return the total length of the string it tried to create.
// --- if (dstsize <= strlen(dst)) ---
// = If there is NO SPACE in the buffer of dst 
// → return (dstsize + strlen(src))
// --- if (dstsize > strlen(dst)) ---
// = If there is SPACE in the buffer of dst
// → return (strlen(dst) + strlen(src))

// === JUDGMENT BASED ON RETURN VALUE ===
// --- If the return value is less than dstsize ---
// Completely appended.
// --- If the return value is equal to or greater than dstsize ---
// src is truncated or not appended with anything in dst.

// === CAUTION ===
// If the dstsize is 0, it returns strlen(src) even if dst is NULL.

#include "../../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (dstsize <= dlen)
		return (dstsize + slen);
	i = 0;
	while (src[i] != '\0' && dlen + i < dstsize - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

// int	main(void)
// {
// 	char	str1[100] = "abcdefg";
// 	char	str2[100] = "1234567890";

// 	// printf("%lu : %s\n", ft_strlcat(str1, str2, sizeof(str1)), str1);
// 	// printf("%lu : %s\n", strlcat(str1, str2, sizeof(str1)), str1);
// 	// printf("%lu : %s\n", ft_strlcat(NULL, str2, 10), str1);
// 	// printf("%lu : %s\n", strlcat(NULL, str2, 10), str1);
// 	// printf("%lu : %s\n", ft_strlcat(NULL, str2, 0), str1);
// 	// printf("%lu : %s\n", strlcat(NULL, str2, 0), str1);
// 	// printf("%lu : %s\n", ft_strlcat(str1, NULL, 10), str1);
// 	// printf("%lu : %s\n", strlcat(str1, NULL, 10), str1);
// 	// printf("%lu : %s\n", ft_strlcat(str1, NULL, 0), str1);
// 	// printf("%lu : %s\n", strlcat(str1, NULL, 0), str1);
// 	// printf("%lu : %s\n", ft_strlcat(str1, str2, 0), str1);
// 	// printf("%lu : %s\n", strlcat(str1, str2, 0), str1);
// 	return (0);
// }
