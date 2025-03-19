/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:47:00 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 18:00:42 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'a';
// 	printf("%c\n", ft_toupper(c));
// 	printf("%c\n", toupper(c));
// 	return (0);
// }
