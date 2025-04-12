/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_no_operand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:50:29 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 19:51:12 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	export_no_operand(t_ctx *ctx)
{
	t_env_list	*env_list_dup;
	t_env_list	*current_node;

	env_list_dup = dup_env_list(ctx->env_list);
	env_list_dup = sort_env_list(env_list_dup);
	current_node = env_list_dup;
	while (current_node != NULL)
	{
		printf("declare -x %s=", get_env_key(current_node));
		printf("\"%s\"\n", get_env_value(current_node));
		current_node = current_node->next;
	}
	clear_env_list(&env_list_dup);
}
