/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:21:35 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:54:28 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Returns the last node of the list.

#include "../../inc/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// static void	ft_printlst(t_list *lst)
// {
// 	if (lst == NULL)
// 	{
// 		printf("lst is NULL.\n");
// 		return ;
// 	}
// 	while (lst != NULL)
// 	{
// 		printf("%s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*last;

// 	head = ft_lstnew("1");
// 	ft_lstadd_front(&head, ft_lstnew("2"));
// 	ft_lstadd_front(&head, ft_lstnew("3"));
// 	ft_lstadd_front(&head, ft_lstnew("4"));
// 	// head = NULL;
// 	last = ft_lstlast(head);
// 	ft_printlst(head);
// 	if (last == NULL)
// 		printf("It seems that NULL was passed as an argument to ft_lstlast.");
// 	else
// 		printf("Last node content is \"%s\"\n", (char *)last->content);
// 	return (0);
// }
