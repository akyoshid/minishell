/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:59:23 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 16:13:49 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_unset_core(t_ctx *ctx, t_cmd_info *cmd_info)
{
	int			i;
	t_env_list	*target_node;

	i = 1 + cmd_info->option_count;
	if (cmd_info->double_dash_flag == true)
		i++;
	while (cmd_info->args[i] != NULL)
	{
		target_node = search_env_node(ctx->env_list, cmd_info->args[i]);
		if (target_node != NULL)
			delete_env_node(&ctx->env_list, target_node);
		i++;
	}
}

void	unset_builtin(t_ctx *ctx, char **cmd_args)
{
	t_cmd_info	cmd_info;

	init_cmd_info1(&cmd_info, cmd_args, "unset", "");
	init_cmd_info2(&cmd_info, OPERAND_NO_LIMIT, false);
	if (check_args(ctx, &cmd_info) == -1)
		return ;
	_unset_core(ctx, &cmd_info);
	ctx->exit_status = EXIT_SUCCESS;
}
