/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:35:05 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:53:53 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Adds the node ’new’ at the end of the list.
// (t_list **lst) expects the address of the head pointer of a linked list.
// The reason for the argument type of ft_lstadd_back being a double pointer is
// to align it with the argument type of the ft_lstadd_front function,
// making it easier to use both functions through a function pointer.

// === RETURN VALUE ===
// if (lst == NULL) → End the function because there is no list to add `new`
// if (new == NULL) → End the function because there is no node to add to `lst`
// if (*lst == NULL) →
// There is a head pointer of a list, but there are no nodes in that list yet.
// Store the address of "new" in the head pointer and end the function.

#include "../../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_node;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current_node = *lst;
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = new;
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

// 	head = ft_lstnew("1");
// 	ft_lstadd_back(&head, ft_lstnew("2"));
// 	ft_lstadd_back(&head, ft_lstnew("3"));
// 	ft_lstadd_back(&head, ft_lstnew("4"));
// 	// ft_lstadd_back(NULL, ft_lstnew("2"));
// 	// ft_lstadd_back(&head, NULL);
// 	// head = NULL;
// 	// ft_lstadd_back(&head, ft_lstnew("2"));
// 	ft_printlst(head);
// 	return (0);
// }
