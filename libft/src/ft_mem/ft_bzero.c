/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:21:05 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:55:02 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// The bzero() function writes n zeroed bytes to the string s.
// If n is zero, bzero() does nothing.

#include "../../inc/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char	str[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 	size_t	i;

// 	for (i = 0; i < sizeof(str); i++)
// 		printf("%d", str[i]);
// 	printf("\n");
// 	ft_bzero(str, 10);
// 	for (i = 0; i < sizeof(str); i++)
// 		printf("%d", str[i]);
// 	printf("\n");
// 	return (0);
// }
