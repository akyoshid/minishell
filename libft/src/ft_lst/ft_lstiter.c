/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:42:40 by akyoshid          #+#    #+#             */
/*   Updated: 2024/11/19 17:54:14 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// === DESCRIPTION ===
// Iterates ’lst’ and applies the function ’f’ on the content of each node.

#include "../../inc/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

// static void	ft_str2upper(void *content)
// {
// 	char	*str;

// 	str = (char *)content;
// 	while (*str != '\0')
// 	{
// 		if (*str >= 'a' && *str <= 'z')
// 			*str -= 'a' - 'A';
// 		str++;
// 	}
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
// 	char	str1[] = "forty";
// 	char	str2[] = "two";
// 	char	str3[] = "tokyo";

// 	head = ft_lstnew(str1);
// 	ft_lstadd_back(&head, ft_lstnew(str2));
// 	ft_lstadd_back(&head, ft_lstnew(str3));
// 	printf("Before ft_lstiter:\n");
// 	ft_printlst(head);
// 	ft_lstiter(head, ft_str2upper);
// 	printf("After ft_lstiter:\n");
// 	ft_printlst(head);
// 	return (0);
// }
