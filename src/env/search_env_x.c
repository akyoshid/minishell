/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:38:00 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 15:31:40 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*search_env_value(t_ctx *ctx, t_env_list *env_list, char *key)
{
	t_env_list	*current_node;

	current_node = env_list;
	while (current_node != NULL)
	{
		if (ft_strcmp(get_env_key(current_node), key) == 0)
			return (get_env_value(current_node));
		current_node = current_node->next;
	}
	if (ft_strcmp("?", key) == 0)
		return (ft_xitoa(ctx->exit_status));
	return (NULL);
}

t_env_list	*search_env_node(t_env_list *env_list, char *key)
{
	t_env_list	*current_node;

	current_node = env_list;
	while (current_node != NULL)
	{
		if (ft_strcmp(get_env_key(current_node), key) == 0)
			return (current_node);
		current_node = current_node->next;
	}
	return (NULL);
}

t_env_list	*search_prev_env_node(
	t_env_list *env_list, t_env_list *current_node)
{
	t_env_list	*temp;

	temp = env_list;
	if (temp == current_node)
		return (NULL);
	while (temp != NULL)
	{
		if (temp->next == current_node)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
