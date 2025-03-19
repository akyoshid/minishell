/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:22:56 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:59:49 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Allocates and returns a copy of ’s1’ 
// with the characters specified in ’set’ removed
// from the beginning and the end of the string

// === RETURN VALUE ===
// if (s1 == NULL) → Return NULL.
// if (set == NULL) → Return copy of s1.
// If all characters are trimmed → Return empty string.

#include "../../inc/libft.h"

static size_t	ft_isset(const char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

// use pointer
char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	char		*buff;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = s1;
	end = start + ft_strlen(s1) - 1;
	while (*start != '\0' && ft_isset(*start, set))
		start++;
	if (*start != '\0')
	{
		while (ft_isset(*end, set))
			end--;
	}
	buff = malloc(end - start + 2);
	if (buff == NULL)
		return (NULL);
	ft_strlcpy(buff, start, end - start + 2);
	return (buff);
}

// // use index
// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char	*buff;
// 	size_t	s1_len;
// 	size_t	start;
// 	size_t	end;

// 	if (s1 == NULL)
// 		return (NULL);
// 	if (set == NULL)
// 		return (ft_strdup(s1));
// 	s1_len = ft_strlen(s1);
// 	start = 0;
// 	while (start < s1_len && ft_isset(s1[start], set))
// 		start++;
// 	if (start == s1_len)
// 		return (ft_calloc(1, 1));
// 	end = s1_len - 1;
// 	while (ft_isset(s1[end], set))
// 		end--;
// 	buff = malloc((end - start + 2) * sizeof(char));
// 	if (buff == NULL)
// 		return (NULL);
// 	ft_strlcpy(buff, s1 + start, end - start + 2);
// 	return (buff);
// }

// int	main(void)
// {
// 	char	str[] = "abcxyz";
// 	char	set[] = "abcz";
// 	// char	set[] = "a";
// 	// char	set[] = "z";
// 	// char	set[] = "abcxyz";
// 	// char	set[] = "";
// 	// char	str[] = "  \t \t \n   \n\n\n\t";
// 	// char	set[] = " \n\t";
// 	// char	*set = NULL;

// 	printf("%s\n", ft_strtrim(str, set));
// 	return (0);
// }
