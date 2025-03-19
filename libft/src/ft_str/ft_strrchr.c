/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:09:31 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:59:46 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Locates the last occurrence of c (converted to a char) in s.
// The terminating null character is considered to be part of the string;
// therefore if c is ‘\0’, the functions locate the terminating ‘\0’.

// === RETURN VALUES ===
// Return a pointer to the located character,
// or NULL if the character does not appear in the string.

#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[11] = "0123401234";
// 	char	*p1;
// 	char	*p2;
// 	char	*p3;

// 	p1 = str + 8;
// 	p2 = ft_strrchr(str, '3');
// 	p3 = strrchr(str, '3');
// 	// p1 = NULL;
// 	// p2 = strrchr(str, 'a');
// 	// p3 = ft_strrchr(str, 'a');
// 	printf("%p\n", (void *)p1);
// 	printf("%p\n", (void *)p2);
// 	printf("%p\n", (void *)p3);
// 	return (0);
// }
