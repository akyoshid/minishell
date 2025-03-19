/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:47:14 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/19 19:48:05 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_xstrndup(const char *s1, size_t n)
{
	char	*temp;

	temp = ft_strndup(s1, n);
	if (temp == NULL)
	{
		ft_dprintf(STDERR_FILENO, "ft_xstrndup: cannot allocate memory\n");
		exit(2);
	}
	return (temp);
}
