/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 22:35:07 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 13:46:17 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// If there are no invalid options, return 0.
// If there are some invalid options, return the index of first invalid option.
static int	_get_invalid_option_i(char *option, char *valid_option_set)
{
	int	i;

	i = 1;
	while (option[i] != '\0')
	{
		if (valid_option_set == NULL)
			return (i);
		if (ft_strchr(valid_option_set, option[i]) != NULL)
			i++;
		else
			return (i);
	}
	return (0);
}

static int	_is_operand(t_cmd_info *cmd_info, int i)
{
	if (cmd_info->args[i][0] != '-')
		return (true);
	else
	{
		if (cmd_info->args[i][1] == '\0')
			return (true);
		if (cmd_info->args[i][1] == '-' && cmd_info->args[i][2] == '\0')
		{
			cmd_info->double_dash_flag = true;
			return (true);
		}
		return (false);
	}
}

static void	_handle_invalid_option(
	t_ctx *ctx, t_cmd_info *cmd_info, int i, int inv_option_i)
{
	if (cmd_info->minishell_flag == true)
		ft_dprintf(STDERR_FILENO,
			"minishell: -%c: invalid option\nUsage: %s\n",
			cmd_info->args[i][inv_option_i], cmd_info->usage);
	else
		ft_dprintf(STDERR_FILENO,
			"minishell: %s: -%c: invalid option\n%s: usage: %s\n",
			cmd_info->name, cmd_info->args[i][inv_option_i],
			cmd_info->name, cmd_info->usage);
	ctx->exit_status = EXIT_USAGE;
	cmd_info->option_count = -1;
}

// If there are no invalid options, return the number of options.
// If there are some invalid options, return -1.
int	count_option(t_ctx *ctx, t_cmd_info *cmd_info)
{
	int	i;
	int	inv_option_i;

	i = 1;
	while (cmd_info->args[i] != NULL)
	{
		if (_is_operand(cmd_info, i) == true)
			break ;
		else
		{
			inv_option_i = _get_invalid_option_i(
					cmd_info->args[i], cmd_info->valid_option_set);
			if (inv_option_i == 0)
				i++;
			else
			{
				_handle_invalid_option(ctx, cmd_info, i, inv_option_i);
				return (-1);
			}
		}
	}
	cmd_info->option_count = i - 1;
	return (cmd_info->option_count);
}
