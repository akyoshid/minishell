/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:15:38 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:54:04 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Use the function `del` to free the content of the node,
// and then free the node itself.
// Execute this on the given node & every successor of that node.
// Finally, the pointer to the list must be set to NULL.

#include "../../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_node;
	t_list	*next_node;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	current_node = *lst;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		(*del)(current_node->content);
		free(current_node);
		current_node = next_node;
	}
	*lst = NULL;
}

// static void	ft_freecontent(void *content)
// {
// 	free(content);
// }

// static void	ft_printlst(t_list *lst)
// {
// 	if (lst == NULL)
// 	{
// 		printf("lst is NULL.\n");
// 		return ;
// 	}
// 	while (lst != NULL)
// 	{
// 		if (lst->content == NULL)
// 			printf("content is freed\n");
// 		else
// 			printf("%s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// }

// int	main(void)
// {
// 	t_list	*head;
// 	int		i;

// 	i = 0;
// 	head = NULL;
// 	while (i < 10)
// 	{
// 		ft_lstadd_back(&head, ft_lstnew((void *)ft_itoa(i)));
// 		i++;
// 	}
// 	printf("Before ft_lstclear: \n");
// 	ft_printlst(head);
// 	printf("After ft_lstclear: \n");
// 	ft_lstclear(&head, ft_freecontent);
// 	ft_printlst(head);
// 	return (0);
// }
