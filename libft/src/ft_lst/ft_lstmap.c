/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:42:41 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:54:33 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Iterate ’lst’ and apply the function ’f’ on the content of each node.
// Create a new list using the content returned from the function ’f’.
// If creating a new node fails, free all nodes of the new list & return NULL.
// In that case, use the `del` function to free the contents of each node.

// === PARAMETERS ===
// 1. Pointer to the first node of a list (lst)
// 2. Function pointer (f)
//    that takes an element of the list and returns a new element
// 3. Function pointer (del) that takes an element of the list and frees it

#include "../../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_lst;
	t_list	*new_node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	mapped_lst = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&mapped_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped_lst, new_node);
		lst = lst->next;
	}
	return (mapped_lst);
}

// static void	*ft_makeupper(void *content)
// {
// 	char	*str;
// 	char	*buff;
// 	int		i;

// 	str = (char *)content;
// 	buff = ft_strdup(str);
// 	if (buff == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (buff[i] != '\0')
// 	{
// 		if (buff[i] >= 'a' && buff[i] <= 'z')
// 			buff[i] -= 'a' - 'A';
// 		i++;
// 	}
// 	return ((void *)buff);
// }

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
// 		printf("%s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*mapped_head;
// 	char	str1[] = "forty";
// 	char	str2[] = "two";
// 	char	str3[] = "tokyo";

// 	head = ft_lstnew(str1);
// 	ft_lstadd_back(&head, ft_lstnew(str2));
// 	ft_lstadd_back(&head, ft_lstnew(str3));
// 	printf("Before ft_lstiter:\n");
// 	printf("%p\n", head);
// 	ft_printlst(head);
// 	mapped_head = ft_lstmap(head, ft_makeupper, ft_freecontent);
// 	printf("After ft_lstiter:\n");
// 	printf("%p\n", mapped_head);
// 	ft_printlst(mapped_head);
// 	ft_lstclear(&mapped_head, ft_freecontent);
// 	return (0);
// }
