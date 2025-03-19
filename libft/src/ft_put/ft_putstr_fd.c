/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:36:51 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:58:39 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === ERROR HANDLING ===
// if (s == NULL) → End the function.

#include "../../inc/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}
