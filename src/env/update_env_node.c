/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:54:17 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 19:21:07 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// `key` and `value` are stored in env_node as duplicates created by strdup()
//  so they must be properly managed in the calling function.
void	update_env_node(
	t_env_list **env_list, char *key, char *value, bool append_flag)
{
	t_env_list	*existing_same_key_node;
	char		*joined_value;

	existing_same_key_node = search_env_node(*env_list, key);
	if (existing_same_key_node == NULL)
		ft_lstadd_back(env_list,
			create_env_node(ft_xstrdup(key), ft_xstrdup(value)));
	else
	{
		if (append_flag == false)
		{
			clear_env_node_value(existing_same_key_node->content);
			set_env_value(existing_same_key_node, ft_xstrdup(value));
		}
		else
		{
			joined_value = ft_xstrjoin(
					get_env_value(existing_same_key_node), value);
			clear_env_node_value(existing_same_key_node->content);
			set_env_value(existing_same_key_node, joined_value);
		}
	}
}
