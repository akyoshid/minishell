/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:42:08 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 19:47:12 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	pwd_builtin(t_ctx *ctx, char **cmd_args)
{
	t_cmd_info	cmd_info;

	init_cmd_info1(&cmd_info, cmd_args, "pwd", "");
	init_cmd_info2(&cmd_info, OPERAND_NO_LIMIT, false);
	if (check_args(ctx, &cmd_info) == -1)
		return ;
	printf("%s\n", ctx->cwd);
	ctx->exit_status = EXIT_SUCCESS;
}
