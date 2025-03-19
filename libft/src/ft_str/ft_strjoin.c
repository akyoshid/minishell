/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:10:49 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 18:00:16 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Allocates and returns a new string by combining 's1' and 's2'.

// === RETURN VALUE ===
// if (s1 == NULL || s2 == NULL) → Return NULL.

#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buff = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	ft_memcpy(buff, s1, s1_len);
	ft_memcpy(buff + s1_len, s2, s2_len);
	buff[s1_len + s2_len] = '\0';
	return (buff);
}

// int	main(void)
// {
// 	char	str1[] = "123";
// 	char	str2[] = "456";
// 	char	*ptr;

// 	ptr = ft_strjoin(str1, str2);
// 	printf("%s\n", ptr);
// 	return (0);
// }
