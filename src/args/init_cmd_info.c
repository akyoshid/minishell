/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:08:49 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 13:16:25 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_cmd_info1(
	t_cmd_info *cmd_info, char **cmd_args, char *usage, char *valid_option_set)
{
	cmd_info->name = cmd_args[0];
	cmd_info->args = cmd_args;
	cmd_info->usage = usage;
	cmd_info->valid_option_set = valid_option_set;
}

void	init_cmd_info2(
	t_cmd_info *cmd_info, int operand_max, bool minishell_flag)
{
	cmd_info->operand_max = operand_max;
	cmd_info->minishell_flag = minishell_flag;
	cmd_info->double_dash_flag = false;
	cmd_info->option_count = 0;
	cmd_info->operand_count = 0;
}
