/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:49:08 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 23:54:16 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	*xmalloc(size_t size)
{
	void	*temp;

	temp = malloc(size);
	if (temp == NULL)
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: malloc: cannot allocate %zu bytes\n", size);
		exit(EXIT_FAILURE);
	}
	return (temp);
}
