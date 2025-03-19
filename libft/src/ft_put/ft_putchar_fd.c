/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:07:30 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:58:21 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === FILE DESCRIPTOR ===
// A unique number assigned to a stream, which is the pathway
// for input and output of data with files, displays, keyboards, etc.

#include "../../inc/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
