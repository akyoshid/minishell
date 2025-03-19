/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:59:43 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:59:06 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Applies the function ’f’ on each character of the string 's'.
// Each character is passed by address to ’f’ to be modified.
// The function 'f' takes the index of the string 's' as its first argument
// and uses it for manipulating characters.

// === RETURN VALUE ===
// if (s == NULL || f == NULL) → End the function.

// === ITERATION ===
// Iteration means the process of repeatedly executing
// the same operation in a specific order on multiple similar objects,
// such as each element of an array.

#include "../../inc/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, s + i);
		i++;
	}
}

// void	ft_addindex(unsigned int i, char *p)
// {
// 	*p += i;
// }

// int	main(void)
// {
// 	char	str[] = "00000";

// 	printf("Before ft_striteri: %s\n", str);
// 	ft_striteri(str, ft_addindex);
// 	// ft_striteri(NULL, ft_addindex);
// 	// ft_striteri(str, NULL);
// 	// ft_striteri(NULL, NULL);
// 	printf("After ft_striteri: %s\n", str);
// 	return (0);
// }
