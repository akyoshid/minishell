/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:15:13 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:59:53 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Allocates and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’.

// === RETURN VALUE ===
// if (s == NULL) → Return NULL.
// if (strlen(s) >= start) → Return empty string.
// if (len == 0) → Return empty string.

#include "../../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	size_t	s_len;
	size_t	sub_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return ((char *)ft_calloc(1, 1));
	if (len > s_len - start)
		sub_len = s_len - start;
	else
		sub_len = len;
	buff = malloc((sub_len + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	ft_strlcpy(buff, s + start, sub_len + 1);
	return (buff);
}

// int	main(void)
// {
// 	char	str[] = "abcdef";

// 	printf("%s\n", ft_substr(str, 1, 1));
// 	printf("%s\n", ft_substr(str, 1, 4));
// 	printf("%s\n", ft_substr(str, 1, 5));
// 	printf("%s\n", ft_substr(str, 1, 6));
// 	printf("%s\n", ft_substr(str, 1, 10));
// 	printf("%s\n", ft_substr(str, 0, 6));
// 	printf("%s\n", ft_substr(str, 6, 6));
// 	printf("%s\n", ft_substr(str, 7, 6));
// 	printf("%s\n", ft_substr(str, 0, 0));
// 	printf("%s\n", ft_substr(str, 0, 42000));
// 	printf("%s\n", ft_substr(NULL, 0, 6));
// 	return (0);
// }
