/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 07:53:01 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:55:11 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Contiguously allocates enough space for count objects that
// are size bytes of memory each and returns a pointer to the allocated memory.
// The allocated memory is filled with bytes of value zero.

// === CAUTION ===
// if (count == 0 || size == 0) → Return 1 byte of memory initialized to 0.
// If count * size exceeds SIZE_MAX → Return NULL.

#include "../../inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr != NULL)
		ft_bzero(ptr, count * size);
	return (ptr);
}

// int	main(void)
// {
// 	char	*str;
// 	size_t	count;
// 	size_t	size;
// 	size_t	i;

// 	count = 10;
// 	// count = 0;
// 	size = sizeof(char);
// 	// size = 0;
// 	str = ft_calloc(count, size);
// 	// str = calloc(count, size);
// 	if (count == 0 || size == 0)
// 	{
// 		// not cause segfalut
// 		printf ("value of str[0] : %d\n", str[0]);
// 		// // cause segfalut
// 		// printf ("value of str[0] : %d\n", str[0]);
// 		// printf ("value of str[1] : %d\n", str[1]);
// 	}
// 	else
// 	{
// 		i = 0;
// 		// not cause segfalut
// 		while (i / size < count)
// 		{
// 			printf ("value of str[%zu] : %d\n", i, str[i]);
// 			i++;
// 		}
// 		// // cause segfalut
// 		// while (i < count * size + 1)
// 		// {
// 		// 	printf ("value of str[%zu] : %d\n", i, str[i]);
// 		// 	i++;
// 		// }
// 	}
// 	free(str);
// 	return (0); 
// }

// int	main(void)
// {
// 	size_t	count;
// 	void	*ptr1;
// 	void	*ptr2;

// 	count = SIZE_MAX;
// 	ptr1 = ft_calloc(count, 2);
// 	ptr2 = calloc(count, 2);
// 	if (ptr1 != NULL && ptr2 != NULL)
// 	{
// 		printf("Test failed : Both didn't behave as expected.\n");
// 		return (1);
// 	}
// 	if (ptr1 != NULL)
// 	{
// 		printf("Test failed : ft_calloc didn't behave as expected.\n");
// 		return (1);
// 	}
// 	if (ptr2 != NULL)
// 	{
// 		printf("Test failed : calloc didn't behave as expected.\n");
// 		return (1);
// 	}
// 	printf("Test passed: Both calloc and ft_calloc behaved as expected.\n");
// 	return (0);
// }
