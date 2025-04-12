/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:47:05 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 17:41:03 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// `fast` moves at double speed, while `slow` moves at half speed.
// When `fast` reaches the end of the list, `slow` is at the middle of the list.
static t_env_list	*_get_middle_node(t_env_list *env_list)
{
	t_env_list	*slow;
	t_env_list	*fast;
	t_env_list	*temp;

	slow = env_list;
	fast = env_list->next;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	temp = slow->next;
	slow->next = NULL;
	return (temp);
}

// Merge while comparing two lists
static t_env_list	*_merge_env_lists(t_env_list *left, t_env_list *right)
{
	t_env_list	dummy;
	t_env_list	*tail;

	tail = &dummy;
	while (left != NULL && right != NULL)
	{
		if (ft_strcmp(get_env_key(left), get_env_key(right)) <= 0)
		{
			tail->next = left;
			left = left->next;
		}
		else
		{
			tail->next = right;
			right = right->next;
		}
		tail = tail->next;
	}
	if (left != NULL)
		tail->next = left;
	else
		tail->next = right;
	return (dummy.next);
}

// Recursively sort the divided list and merge the two sorted lists.
t_env_list	*sort_env_list(t_env_list *env_list)
{
	t_env_list	*middle;
	t_env_list	*left;
	t_env_list	*right;

	if (env_list == NULL || env_list->next == NULL)
		return (env_list);
	middle = _get_middle_node(env_list);
	left = sort_env_list(env_list);
	right = sort_env_list(middle);
	return (_merge_env_lists(left, right));
}
