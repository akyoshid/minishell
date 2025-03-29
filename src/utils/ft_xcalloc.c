/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xcalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:47:14 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/29 21:52:55 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	*ft_xcalloc(size_t count, size_t size)
{
	char	*temp;

	temp = ft_calloc(count, size);
	if (temp == NULL)
	{
		ft_dprintf(STDERR_FILENO, "ft_xcalloc: cannot allocate memory\n");
		exit(EXIT_USAGE);
	}
	return (temp);
}
