/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:38:11 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:55:50 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// The memmove() function copies len bytes from string src to string dst.
// Even if two strings overlap, they will be safely copied.

// === BEHAVIOR ===
// If both of dst and src are NULL, memcpy() returns NULL.

// === HOW TO SOLVE THE PROBLEM OF OVERLAP ===
// if (dst <= src) → Copy in order from the front. (Same as memcpy)
// if (dst > src) → Copy in order from the back.

#include "../../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			dst_ptr[len - 1] = src_ptr[len - 1];
			len--;
		}
	}
	return (dst);
}

// int	main(void)
// {
// 	char	str1[11] = "0123456789";
// 	char	str2[11] = "0123456789";
// 	char	str3[11] = "0123456789";

// 	ft_memmove(str1 + 3, str1, 7);
// 	memmove(str2 + 3, str2, 7);
// 	memcpy(str3 + 3, str2, 7);
// 	// ft_memmove(str1, str1 + 3, 7);
// 	// memmove(str2, str2 + 3, 7);
// 	// memcpy(str3, str3 + 3, 7);
// 	// ft_memmove(str1, str1, 7);
// 	// memmove(str2, str2, 7);
// 	// memcpy(str3, str3, 7);
// 	// ft_memmove(str1, str1 + 3, 0);
// 	// memmove(str2, str2 + 3, 0);
// 	// memcpy(str3, str3 + 3, 0);
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	printf("%s\n", str3);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*str1 = NULL;

// 	// ft_memmove(str1 + 3, str1, 7);
// 	// memmove(str1 + 3, str1, 7);
// 	// ft_memmove(str1, str1 + 3, 7);
// 	// memmove(str1, str1 + 3, 7);
// 	ft_memmove(str1, NULL, 7);
// 	// memmove(str1, NULL, 7);
// 	printf("%s\n", str1);
// 	return (0);
// }
