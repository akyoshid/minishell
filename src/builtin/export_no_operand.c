/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_no_operand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:50:29 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/14 02:33:52 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	export_no_operand(t_ctx *ctx)
{
	t_env_list	*env_list_dup;
	t_env_list	*current_node;
	char		*key;
	char		*value;

	env_list_dup = dup_env_list(ctx->env_list);
	env_list_dup = sort_env_list(env_list_dup);
	current_node = env_list_dup;
	while (current_node != NULL)
	{
		key = get_env_key(current_node);
		value = get_env_value(current_node);
		if (ft_strcmp(key, "_") != 0)
		{
			printf("declare -x %s=", key);
			printf("\"%s\"\n", value);
		}
		current_node = current_node->next;
	}
	clear_env_list(&env_list_dup);
}
