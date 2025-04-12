/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:17:52 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 17:30:00 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_env_list	*dup_env_list(t_env_list *env_list)
{
	t_env_list	*env_list_dup;
	t_env_list	*current_node;
	char		*key_dup;
	char		*value_dup;

	env_list_dup = NULL;
	current_node = env_list;
	while (current_node != NULL)
	{
		key_dup = ft_xstrdup(get_env_key(current_node));
		value_dup = ft_xstrdup(get_env_value(current_node));
		ft_lstadd_back(&env_list_dup, create_env_node(key_dup, value_dup));
		current_node = current_node->next;
	}
	return (env_list_dup);
}
