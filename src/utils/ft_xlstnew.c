/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:05:23 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/02 23:53:57 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_list	*ft_xlstnew(void *content)
{
	t_list	*temp;

	temp = ft_lstnew(content);
	if (temp == NULL)
	{
		print_error("malloc", "cannot allocate memory", NULL, false);
		exit(EXIT_FAILURE);
	}
	return (temp);
}
