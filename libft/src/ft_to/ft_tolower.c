/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:51:26 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 18:00:38 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'A';
// 	printf("%c\n", ft_tolower(c));
// 	printf("%c\n", tolower(c));
// 	return (0);
// }
