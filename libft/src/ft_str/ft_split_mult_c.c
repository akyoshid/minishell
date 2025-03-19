/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mult_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:47:17 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/16 18:36:47 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Allocates and returns an array of strings
// obtained by splitting `s` using the delimiter string `sep`.
// The array must end with a NULL pointer.

// === RETURN VALUE ===
// - if (s == NULL) → Return NULL
// - if (sep == NULL) → Return a new array with a single element: a copy of `s`.
// 	 This array is terminated by a NULL pointer.

#include "../../inc/libft.h"

static int	check_include_sep(char const c, char *sep)
{
	int	i;

	i = 0;
	if (sep == NULL)
		return (1);
	while (sep[i] != '\0')
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	**ft_freemem(char ***p, int last_index)
{
	int	i;

	i = 0;
	while (i < last_index)
	{
		free((*p)[i]);
		(*p)[i] = NULL;
		i++;
	}
	free(*p);
	*p = NULL;
	return (NULL);
}

static int	ft_countword(char const *s, char *sep)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && (check_include_sep(*s, sep) == 1))
			s++;
		if (*s != '\0')
			count++;
		while (*s != '\0' && (check_include_sep(*s, sep) == 0))
			s++;
	}
	return (count);
}

static char	*ft_storeword(char const **s, char *sep)
{
	char	*temp;
	int		len;

	len = 0;
	while (**s != '\0' && (check_include_sep(**s, sep) == 0))
	{
		len++;
		(*s)++;
	}
	temp = malloc((len + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	ft_strlcpy(temp, *s - len, len + 1);
	return (temp);
}

char	**ft_split_mult_c(char const *s, char *sep)
{
	char	**buff;
	int		wordcount;
	int		i;

	if (s == NULL)
		return (NULL);
	wordcount = ft_countword(s, sep);
	buff = malloc((wordcount + 1) * sizeof(char *));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && (check_include_sep(*s, sep) == 1))
			s++;
		if (*s != '\0')
		{
			buff[i] = ft_storeword(&s, sep);
			if (buff[i] == NULL)
				return (ft_freemem(&buff, i));
			i++;
		}
	}
	buff[i] = NULL;
	return (buff);
}
