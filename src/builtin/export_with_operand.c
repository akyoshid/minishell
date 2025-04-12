/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_with_operand.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:50:11 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/12 19:54:56 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// On success, it returns 0.
// On error, it returns -1.
static int	_init_export_info(
	t_ctx *ctx, t_export_info *export_info, char *operand)
{
	int	i;

	i = 0;
	while (operand[i] != '\0')
	{
		if (operand[i] == '=')
		{
			export_info->value = ft_xstrdup(operand + i + 1);
			export_info->type = EXPORT_ASSIGN;
			if (i != 0 && operand[i - 1] == '+')
			{
				export_info->type = EXPORT_APPEND;
				export_info->key = ft_xstrndup(operand, i - 1);
			}
			else
				export_info->key = ft_xstrndup(operand, i);
			return (0);
		}
		i++;
	}
	ft_dprintf(STDERR_FILENO, "minishell: export: `%s': missing value "
		"assignment\n""export: usage: export [name=value ...]\n", operand);
	ctx->exit_status = EXIT_USAGE;
	return (-1);
}

// If key is valid, it returns 1.
// If not, it returns 0.
static int	_is_valid_key(t_ctx *ctx, t_export_info *export_info, char *operand)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i != 0 && export_info->key[i] == '\0')
			return (1);
		else if (is_avail_char_for_var_name(export_info->key[i]) != 1
			|| (i == 0 && ft_isdigit(export_info->key[0]) == 1))
		{
			ft_dprintf(STDERR_FILENO,
				"minishell: export: `%s': not a valid identifier\n", operand);
			free(export_info->key);
			free(export_info->value);
			ctx->exit_status = EXIT_FAILURE;
			return (0);
		}
		else
			i++;
	}
}

static void	_export_with_operand_core(t_ctx *ctx, t_export_info *export_info)
{
	t_env_list	*existing_same_key_node;
	char		*joined_value;

	existing_same_key_node = search_env_node(ctx->env_list, export_info->key);
	if (existing_same_key_node == NULL)
		ft_lstadd_back(&ctx->env_list,
			create_env_node(export_info->key, export_info->value));
	else
	{
		free(export_info->key);
		if (export_info->type == EXPORT_ASSIGN)
		{
			clear_env_node_value(existing_same_key_node->content);
			set_env_value(existing_same_key_node, export_info->value);
		}
		else
		{
			joined_value = ft_xstrjoin(
					get_env_value(existing_same_key_node), export_info->value);
			clear_env_node_value(existing_same_key_node->content);
			free(export_info->value);
			set_env_value(existing_same_key_node, joined_value);
		}
	}
}

// On success, it returns 0.
// On error, it returns -1.
int	export_with_operand(t_ctx *ctx, t_cmd_info *cmd_info)
{
	int				i;
	t_export_info	export_info;

	i = 1 + cmd_info->option_count;
	if (cmd_info->double_dash_flag == true)
		i++;
	while (cmd_info->args[i] != NULL)
	{
		if (_init_export_info(ctx, &export_info, cmd_info->args[i]) == -1)
			return (-1);
		if (_is_valid_key(ctx, &export_info, cmd_info->args[i]) == 0)
			return (-1);
		_export_with_operand_core(ctx, &export_info);
		i++;
	}
	return (0);
}
