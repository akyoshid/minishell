/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:49:08 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/20 13:14:33 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	*xmalloc(size_t size)
{
	void	*temp;

	temp = malloc(size);
	if (temp == NULL)
	{
		ft_dprintf(STDERR_FILENO, "xmalloc: cannot allocate %zu bytes\n", size);
		exit(EXIT_USAGE);
	}
	return (temp);
}
