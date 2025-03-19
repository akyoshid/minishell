/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:34:31 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:55:35 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// The memcpy() function copies n bytes from memory area src to memory area dst.
// If dst and src overlap, behavior is undefined.
// Applications in which dst and src might overlap should use memmove instead.

// === BEHAVIOR ===
// If both of dst and src are NULL, memcpy() returns NULL.

#include "../../inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	str1[22] = "abcdefghijklmnopqrstu";
// 	char	str2[22] = "abcdefghijklmnopqrstu";
// 	// char	*str1 = NULL;
// 	// char	*str2 = NULL;

// 	memcpy(str1 + 4, str1, 10);
// 	ft_memcpy(str2 + 4, str2, 10);
// 	// memcpy(str1, str2, 10);
// 	// ft_memcpy(str1, str2, 10);
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	return (0);
// }