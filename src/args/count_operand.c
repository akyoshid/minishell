/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:09:03 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 13:31:33 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_print_extra_operand_for_minishell(t_cmd_info *cmd_info)
{
	if (cmd_info->double_dash_flag == false)
		ft_dprintf(STDERR_FILENO,
			"minishell: extra operand ‘%s’\nUsage: %s\n",
			cmd_info->args[1 + cmd_info->option_count + cmd_info->operand_max],
			cmd_info->usage);
	else
		ft_dprintf(STDERR_FILENO,
			"minishell: extra operand ‘%s’\nUsage: %s\n",
			cmd_info->args[2 + cmd_info->option_count + cmd_info->operand_max],
			cmd_info->usage);
}

static void	_print_extra_operand_for_builtin(t_cmd_info *cmd_info)
{
	if (cmd_info->double_dash_flag == false)
		ft_dprintf(STDERR_FILENO,
			"minishell: %s: extra operand ‘%s’\n%s: usage: %s\n",
			cmd_info->name,
			cmd_info->args[1 + cmd_info->option_count + cmd_info->operand_max],
			cmd_info->name, cmd_info->usage);
	else
		ft_dprintf(STDERR_FILENO,
			"minishell: %s: extra operand ‘%s’\n%s: usage: %s\n",
			cmd_info->name,
			cmd_info->args[2 + cmd_info->option_count + cmd_info->operand_max],
			cmd_info->name, cmd_info->usage);
}

static void	_handle_extra_operand(t_ctx *ctx, t_cmd_info *cmd_info)
{
	if (cmd_info->minishell_flag == true)
		_print_extra_operand_for_minishell(cmd_info);
	else
		_print_extra_operand_for_builtin(cmd_info);
	ctx->exit_status = EXIT_USAGE;
	cmd_info->operand_count = -1;
}

int	count_operand(t_ctx *ctx, t_cmd_info *cmd_info)
{
	int		i;

	i = 0;
	while (cmd_info->args[1 + cmd_info->option_count + i] != NULL)
		i++;
	if (cmd_info->double_dash_flag == true)
		i--;
	cmd_info->operand_count = i;
	if (cmd_info->operand_max == OPERAND_NO_LIMIT)
		return (cmd_info->operand_count);
	else if (cmd_info->operand_max < cmd_info->operand_count)
	{
		_handle_extra_operand(ctx, cmd_info);
		return (-1);
	}
	return (cmd_info->operand_count);
}
