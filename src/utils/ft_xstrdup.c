/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:47:14 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/19 19:42:38 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_xstrdup(const char *s1)
{
	char	*temp;

	temp = ft_strdup(s1);
	if (temp == NULL)
	{
		ft_dprintf(STDERR_FILENO, "ft_xstrdup: cannot allocate memory\n");
		exit(2);
	}
	return (temp);
}
