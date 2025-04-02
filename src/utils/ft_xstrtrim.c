/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:07:50 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 23:54:13 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_xstrtrim(const char *s1, const char *set)
{
	char	*temp;

	temp = ft_strtrim(s1, set);
	if (temp == NULL)
	{
		print_error("malloc", "cannot allocate memory", NULL, false);
		exit(EXIT_FAILURE);
	}
	return (temp);
}
