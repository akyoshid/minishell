/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:47:14 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:59:01 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Allocates sufficient memory for a copy of the string s1,
// does the copy, and returns a pointer to it.
// The pointer can be used as an argument for the function free.
// If sufficient memory is not available, NULL is returned.

#include "../../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*temp;

	len = ft_strlen(s1);
	temp = malloc((len + 1) * sizeof(char));
	if (temp != NULL)
		ft_strlcpy(temp, s1, len + 1);
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
