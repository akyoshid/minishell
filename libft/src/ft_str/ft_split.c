/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:47:17 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:58:51 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Allocates and returns an array of strings
// obtained by splitting ’s’ using the character ’c’ as a delimiter.
// The array must end with a NULL pointer.

// === RETURN VALUE ===
// if (s == NULL) → Return NULL

#include "../../inc/libft.h"

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

static int	ft_countword(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_storeword(char const **s, char c)
{
	char	*temp;
	int		len;

	len = 0;
	while (**s != '\0' && **s != c)
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

char	**ft_split(char const *s, char c)
{
	char	**buff;
	int		wordcount;
	int		i;

	if (s == NULL)
		return (NULL);
	wordcount = ft_countword(s, c);
	buff = malloc((wordcount + 1) * sizeof(char *));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			buff[i] = ft_storeword(&s, c);
			if (buff[i] == NULL)
				return (ft_freemem(&buff, i));
			i++;
		}
	}
	buff[i] = NULL;
	return (buff);
}

// int	main(void)
// {
// 	char	str[] = "---abc--xyz---";
// 	char	c = '-';
// 	char	**ptr;
// 	int		i;
// 	int		word_count;

// 	ptr = ft_split(str, c);
// 	i = 0;
// 	word_count = ft_countword(str, c);
// 	while (i < word_count + 1)
// 	{
// 		printf("%s\n", ptr[i]);
// 		i++;
// 	}
// 	ft_freemem(&ptr, word_count);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*str = NULL;
// 	char	c = 'b';
// 	char	**ptr;

// 	ptr = ft_split(str, c);
// 	if (ptr == NULL)
// 		printf("Success: ptr is NULL.\n");
// 	else
// 		printf("Failure: ptr is not NULL.\n");
// 	return (0);
// }

/* ************************************************************************** */
// This is the second version I wrote.
// ft_storeword allocates memory for multiple words at once.
// I feel the first version is more readable.
/* ************************************************************************** */

// static char	**ft_freemem(char **p, int count)
// {
// 	int	i;

// 	i = 0;
// 	while (i < count)
// 	{
// 		free(p[i]);
// 		p[i] = NULL;
// 		i++;
// 	}
// 	free(p);
// 	p = NULL;
// 	return (p);
// }

// static int	ft_countword(const char *s, char c)
// {
// 	int	count;

// 	count = 0;
// 	while (*s != '\0')
// 	{
// 		while (*s != '\0' && *s == c)
// 			s++;
// 		if (*s != '\0')
// 			count++;
// 		while (*s != '\0' && *s != c)
// 			s++;
// 	}
// 	return (count);
// }

// static char	**ft_storeword(char **p, const char *s, char c, int wordcount)
// {
// 	int		i;
// 	int		word_len;

// 	i = 0;
// 	while (*s != '\0')
// 	{
// 		word_len = 0;
// 		while (*s != '\0' && *s == c)
// 			s++;
// 		while (*s != '\0' && *s != c)
// 		{
// 			s++;
// 			word_len++;
// 		}
// 		if (i < wordcount)
// 		{
// 			p[i] = malloc((word_len + 1) * sizeof(char));
// 			if (p[i] == NULL)
// 				return (ft_freemem(p, i));
// 			ft_strlcpy(p[i], s - word_len, word_len + 1);
// 			i++;
// 		}
// 	}
// 	return (p);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**buff;
// 	int		wordcount;

// 	if (s == NULL)
// 		return (NULL);
// 	wordcount = ft_countword(s, c);
// 	buff = malloc((wordcount + 1) * sizeof(char *));
// 	if (buff == NULL)
// 		return (NULL);
// 	if ((ft_storeword(buff, s, c, wordcount)) != NULL)
// 		buff[wordcount] = NULL;
// 	return (buff);
// }

/* ************************************************************************** */
// This is the first version I wrote.
// ft_storeword allocates memory for single word at once.
// ft_split calls ft_storeword multiple times.
/* ************************************************************************** */

// static void	*ft_freemem(char **buff, int last_index)
// {
// 	int	i;

// 	i = 0;
// 	while (i < last_index)
// 	{
// 		free(buff[i]);
// 		buff[i] = NULL;
// 		i++;
// 	}
// 	free(buff);
// 	buff = NULL;
// 	return (NULL);
// }

// static int	ft_countstr(char const *s, char c)
// {
// 	int	count;

// 	count = 0;
// 	while (*s != '\0')
// 	{
// 		while (*s != '\0' && *s == c)
// 			s++;
// 		if (*s != '\0')
// 			count++;
// 		while (*s != '\0' && *s != c)
// 			s++;
// 	}
// 	return (count);
// }

// static char	*ft_storeword(char const **s, char c)
// {
// 	int			count;
// 	const char	*start;
// 	char		*buff;

// 	while (**s == c)
// 		(*s)++;
// 	start = *s;
// 	count = 0;
// 	while (**s != '\0' && **s != c)
// 	{
// 		count++;
// 		(*s)++;
// 	}
// 	buff = malloc((count + 1) * sizeof(char));
// 	if (buff == NULL)
// 		return (NULL);
// 	ft_memcpy(buff, start, count);
// 	buff[count] = '\0';
// 	return (buff);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**buff;
// 	int		i;
// 	int		str_count;

// 	if (s == NULL)
// 		return (NULL);
// 	str_count = ft_countstr(s, c);
// 	buff = malloc((str_count + 1) * sizeof(char *));
// 	if (buff == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < str_count)
// 	{
// 		buff[i] = ft_storeword(&s, c);
// 		if (buff[i] == NULL)
// 			return (ft_freemem(buff, i));
// 		i++;
// 	}
// 	buff[str_count] = NULL;
// 	return (buff);
// }
