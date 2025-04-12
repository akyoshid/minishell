/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_env_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:42:46 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 15:43:15 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	delete_env_node(t_env_list **env_list, t_env_list *target_node)
{
	t_env_list	*prev_node;

	if (env_list == NULL || *env_list == NULL || target_node == NULL)
		return ;
	prev_node = search_prev_env_node(*env_list, target_node);
	if (prev_node == NULL)
		*env_list = target_node->next;
	else
		prev_node->next = target_node->next;
	ft_lstdelone(target_node, clear_env_node_content);
}
