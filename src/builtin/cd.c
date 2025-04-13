/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:00:00 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 20:45:23 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// On success, it returns 0.
// On error, it returns -1.
static int	_cd_to_home(t_ctx *ctx)
{
	char	*path;

	path = search_env_value(ctx, ctx->env_list, "HOME");
	if (path == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: cd: HOME not set\n");
		ctx->exit_status = EXIT_FAILURE;
		return (-1);
	}
	if (w_chdir(ctx, path) == -1)
		return (-1);
	else
	{
		update_wd_data(ctx, path);
		return (0);
	}
}

// On success, it returns 0.
// On error, it returns -1.
static int	_cd_to_operand(t_ctx *ctx, char *operand)
{
	if (w_chdir(ctx, operand) == -1)
		return (-1);
	else
	{
		update_wd_data(ctx, operand);
		return (0);
	}
}

void	cd_builtin(t_ctx *ctx, char **cmd_args)
{
	t_cmd_info	cmd_info;

	init_cmd_info1(&cmd_info, cmd_args, "cd [dir]", "");
	init_cmd_info2(&cmd_info, 1, false);
	if (check_args(ctx, &cmd_info) == -1)
		return ;
	if (cmd_info.operand_count == 0)
	{
		if (_cd_to_home(ctx) == -1)
			return ;
	}
	else
	{
		if (_cd_to_operand(ctx, get_operand(&cmd_info, 0)) == -1)
			return ;
	}
	ctx->exit_status = EXIT_SUCCESS;
}
