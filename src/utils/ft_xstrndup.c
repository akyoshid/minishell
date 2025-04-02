/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:47:14 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 23:54:11 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_xstrndup(const char *s1, size_t n)
{
	char	*temp;

	temp = ft_strndup(s1, n);
	if (temp == NULL)
	{
		print_error("malloc", "cannot allocate memory", NULL, false);
		exit(EXIT_FAILURE);
	}
	return (temp);
}
