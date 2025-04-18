/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:49:58 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 12:30:23 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	env_builtin(t_ctx *ctx, char **cmd_args)
{
	t_cmd_info	cmd_info;

	init_cmd_info1(&cmd_info, cmd_args, "env", "");
	init_cmd_info2(&cmd_info, 0, false);
	if (check_args(ctx, &cmd_info) == -1)
		return ;
	print_env_list(ctx->env_list);
	ctx->exit_status = EXIT_SUCCESS;
}
