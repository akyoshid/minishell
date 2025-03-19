/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:05:23 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:54:40 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === LINKED LISTS ===
// Linked lists are suitable when the number of elements is indefinite
// and data insertion or deletion is frequent.
// When inserting or deleting elements in the middle of a linked lists,
// it is efficient because it only requires adjustments of pointer.

// === DESCRIPTION ===
// Allocates and returns a new node.
// The member variable ’content’ is initialized with
// the value of the parameter ’content’.
// The variable ’next’ is initialized to NULL

// === RETURN VALUE ===
// Even if NULL is passed to content,
// create a new node and make its content point to a NULL pointer.

#include "../../inc/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*buff;

	buff = malloc(1 * sizeof(t_list));
	if (buff == NULL)
		return (NULL);
	buff->content = content;
	buff->next = NULL;
	return (buff);
}

// int	main(void)
// {
// 	t_list	*head;

// 	head = ft_lstnew("Success");
// 	// head = ft_lstnew(NULL);
// 	printf("%s\n", (char *)head->content);
// 	free(head);
// 	return (0);
// }
