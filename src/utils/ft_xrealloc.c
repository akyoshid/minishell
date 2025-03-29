/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xrealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:47:14 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/29 21:42:49 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	*ft_xrealloc(void *ptr, size_t old_size, size_t new_size)
{
	char	*temp;

	temp = ft_realloc(ptr, old_size, new_size);
	if (temp == NULL)
	{
		ft_dprintf(STDERR_FILENO, "ft_xrealloc: cannot allocate memory\n");
		exit(EXIT_USAGE);
	}
	return (temp);
}
