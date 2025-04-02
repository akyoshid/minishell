/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:47:14 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 23:54:05 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_xstrdup(const char *s1)
{
	char	*temp;

	temp = ft_strdup(s1);
	if (temp == NULL)
	{
		print_error("malloc", "cannot allocate memory", NULL, false);
		exit(EXIT_FAILURE);
	}
	return (temp);
}
