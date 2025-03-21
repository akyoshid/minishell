/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:51:08 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/21 14:52:08 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_xstrjoin(char const *s1, char const *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	if (temp == NULL)
	{
		ft_dprintf(STDERR_FILENO, "ft_xstrjoin: cannot allocate memory\n");
		exit(EXIT_USAGE);
	}
	return (temp);
}
