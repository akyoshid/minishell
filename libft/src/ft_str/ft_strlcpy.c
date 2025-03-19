/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:25:11 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:59:19 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === BEHAVIOR ===
// Copy up to dstsize-1 bytes from src to dst.
// The copied string in dst will always be NULL-terminate.
// If (dstsize <= 0) → Just return the length of src.

// === RETURN VALUE ===
// The return value is the length of src, not including '\0'.
// If the return value is >= dstsize, it means that truncation occurred.

#include "../../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	str1[100] = "abcdefg";
// 	char	str2[100] = "1234567890";
// 	char	*str3 = NULL;

// 	// printf("%lu : %s\n", ft_strlcpy(str1, str2, sizeof(str1)), str1);
// 	// printf("%lu : %s\n", strlcpy(str1, str2, sizeof(str1)), str1);
// 	// printf("%lu : %s\n", ft_strlcpy(str3, str2, 10), str1);
// 	// printf("%lu : %s\n", strlcpy(str3, str2, 10), str1);
// 	// printf("%lu : %s\n", ft_strlcpy(str1, str3, 10), str1);
// 	// printf("%lu : %s\n", strlcpy(str1, str3, 10), str1);
// 	// printf("%lu : %s\n", ft_strlcpy(str1, str2, 0), str1);
// 	printf("%lu : %s\n", strlcpy(str1, str2, 0), str1);
// 	return (0);
// }
