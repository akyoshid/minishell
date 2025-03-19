/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:14:08 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:54:44 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// int	main(void)
// {
// 	t_list	*head;

// 	head = NULL;
// 	head = ft_lstnew("1");
// 	ft_lstadd_front(&head, ft_lstnew("2"));
// 	ft_lstadd_front(&head, ft_lstnew("3"));
// 	ft_lstadd_front(&head, ft_lstnew("4"));
// 	printf("%d\n", ft_lstsize(head));
// 	return (0);
// }
