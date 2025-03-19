/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:57:39 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:54:07 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// lst: The node to free
// Takes as a parameter a node and frees the memory of the node’s content
// using the function ’del’ given as a parameter
// and free the node.
// The memory of ’next’ must not be freed.

#include "../../inc/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	(*del)(lst->content);
	lst->content = NULL;
	free(lst);
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

// static t_list	*ft_lstindex(t_list *lst, int index)
// {
// 	int	i;

// 	if (lst == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (lst->next != NULL && i < index)
// 	{
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (lst);
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*target;
// 	int		i;

// 	head = NULL;
// 	i = 0;
// 	while (i < 10)
// 	{
// 		ft_lstadd_back(&head, ft_lstnew((void *)ft_itoa(i)));
// 		i++;
// 	}
// 	printf("Before ft_lstdelone:\n");
// 	ft_printlst(head);
// 	target = ft_lstindex(head, 5);
// 	ft_lstdelone(target, ft_freecontent);
// 	printf("After ft_lstdelone:\n");
// 	ft_printlst(head);
// 	return (0);
// }
