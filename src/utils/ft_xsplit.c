/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:20:05 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/04 23:21:23 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**ft_xsplit(char const *s, char c)
{
	char	**temp;

	temp = ft_split(s, c);
	if (temp == NULL)
	{
		print_error("malloc", "cannot allocate memory", NULL, false);
		exit(EXIT_FAILURE);
	}
	return (temp);
}
