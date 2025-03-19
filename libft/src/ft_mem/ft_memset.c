/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:00:53 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:55:54 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// The memset() function writes len bytes of value c
// (converted to an unsigned char) to the string b.

// === WHY WE USE UNSIGNED CHAR FOR MEMORY OPERATION? ===
// Because unsigned char is the only binary-safe data type.

#include "../../inc/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	ptr = (unsigned char *)b;
	ch = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptr[i] = ch;
		i++;
	}
	return (b);
}

// int	main(void)
// {
// 	unsigned char	str1[11] = "0123456789";
// 	unsigned char	str2[11] = "0123456789";

// 	ft_memset(str1, 256 + 'a', 5);
// 	memset(str2, 256 + 'a', 5);
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	return (0);
// }
