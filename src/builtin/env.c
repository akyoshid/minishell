/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:49:58 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/11 22:55:07 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	env_builtin(t_ctx *ctx, char **cmd_args)
{
	if (count_valid_option(ctx, cmd_args, NULL, "env") == -1)
		return ;
	print_env_list(ctx->env_list);
	ctx->exit_status = EXIT_SUCCESS;
}
