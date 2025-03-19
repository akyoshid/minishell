/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:05:23 by akyoshid          #+#    #+#             */
/*   Updated: 2025/03/19 19:48:13 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_list	*ft_xlstnew(void *content)
{
	t_list	*temp;

	temp = ft_lstnew(content);
	if (temp == NULL)
	{
		ft_dprintf(STDERR_FILENO, "ft_lstnew: cannot allocate memory\n");
		exit(2);
	}
	return (temp);
}
