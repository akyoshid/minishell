/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:17:04 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 19:53:49 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	export_builtin(t_ctx *ctx, char **cmd_args)
{
	t_cmd_info	cmd_info;

	init_cmd_info1(&cmd_info, cmd_args, "export [name=value ...]", "");
	init_cmd_info2(&cmd_info, OPERAND_NO_LIMIT, false);
	if (check_args(ctx, &cmd_info) == -1)
		return ;
	if (cmd_info.operand_count == 0)
		export_no_operand(ctx);
	else if (export_with_operand(ctx, &cmd_info) == -1)
		return ;
	ctx->exit_status = EXIT_SUCCESS;
}
