/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:07:12 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:55:22 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Locates the first occurrence of c (converted to an unsigned char) in s.

// === RETURN VALUES ===
// Return a pointer to the byte located, or NULL if no match within n bytes.

#include "../../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == ch)
			return (ptr + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "0123456789";
// 	int		c = '309';

// 	printf("%p\n", str + 5);
// 	printf("%p\n", memchr(str, c, 11));
// 	printf("%p\n", ft_memchr(str, c, 11));
// 	printf("%c\n", (unsigned char)c);
// 	return (0);
// }
