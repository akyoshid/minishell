/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:47:14 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/19 19:06:19 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// The strndup() function is similar to strdup(), but copies at most n bytes.
// If s is longer than n, only n bytes are copied,
//  and a terminating null byte ('\0') is added.
// The pointer can be used as an argument for the function free.
// If sufficient memory is not available, NULL is returned.

#include "../../inc/libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	s1_len;
	size_t	copy_len;
	char	*temp;

	s1_len = ft_strlen(s1);
	if (n < s1_len)
		copy_len = n;
	else
		copy_len = s1_len;
	temp = malloc((copy_len + 1) * sizeof(char));
	if (temp != NULL)
		ft_strlcpy(temp, s1, copy_len + 1);
	return (temp);
}

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;

// 	str1 = ft_strdup("abcdefg");
// 	str2 = strdup("abcdefg");
// 	// str1 = ft_strdup(NULL);
// 	// str2 = strdup(NULL);

// 	if (str1 == NULL)
// 		printf("str1 is NULL\n");
// 	else
// 		printf("str1 : %s\n", str1);
// 	free (str1);
// 	if (str2 == NULL)
// 		printf("str2 is NULL\n");
// 	else
// 		printf("str2 : %s\n", str2);
// 	free (str2);
// 	return (0);
// }
