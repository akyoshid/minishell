/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:56:21 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:58:57 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Locates the first occurrence of c (converted to a char) in s.
// The terminating null character is considered to be part of the string;
// therefore if c is ‘\0’, the functions locate the terminating ‘\0’.

// === RETURN VALUES ===
// Return a pointer to the located character,
// or NULL if the character does not appear in the string.

#include "../../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (1)
	{
		if (*s == ch)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}

// int	main(void)
// {
// 	char	str[] = "0123456789";
// 	char	*p1;
// 	char	*p2;
// 	char	*p3;

// 	p1 = str + 4;
// 	p2 = ft_strchr(str, '4');
// 	p3 = strchr(str, '4');
// 	// p1 = NULL;
// 	// p2 = ft_strchr(str, 'a');
// 	// p3 = strchr(str, 'a');
// 	printf("%p\n", (void *)p1);
// 	printf("%p\n", (void *)p2);
// 	printf("%p\n", (void *)p3);
// 	return (0);
// }
