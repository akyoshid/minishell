/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:14:24 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/10 08:50:14 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_cmd_is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (true);
	// else if (ft_strcmp(cmd, "cd") == 0)
	// 	return (true);
	// else if (ft_strcmp(cmd, "pwd") == 0)
	// 	return (true);
	// else if (ft_strcmp(cmd, "export") == 0)
	// 	return (true);
	// else if (ft_strcmp(cmd, "unset") == 0)
	// 	return (true);
	// else if (ft_strcmp(cmd, "env") == 0)
	// 	return (true);
	// else if (ft_strcmp(cmd, "exit") == 0)
	// 	return (true);
	else if (ft_strcmp(cmd, ":") == 0)
		return (true);
	return (false);
}

void	exec_builtin_command(t_ctx *ctx, t_ast *ast_node)
{
	if (ft_strcmp(ast_node->cmd_args[0], "echo") == 0)
		echo_builtin(ctx, ast_node->cmd_args);
	// else if (ft_strcmp(ast_node->cmd_args[0], "cd") == 0)
	// 	cd_builtin(ctx, ast_node->cmd_args);
	// else if (ft_strcmp(ast_node->cmd_args[0], "pwd") == 0)
	// 	pwd_builtin(ctx, ast_node->cmd_args);
	// else if (ft_strcmp(ast_node->cmd_args[0], "export") == 0)
	// 	export_builtin(ctx, ast_node->cmd_args);
	// else if (ft_strcmp(ast_node->cmd_args[0], "unset") == 0)
	// 	unset_builtin(ctx, ast_node->cmd_args);
	// else if (ft_strcmp(ast_node->cmd_args[0], "env") == 0)
	// 	env_builtin(ctx, ast_node->cmd_args);
	// else if (ft_strcmp(ast_node->cmd_args[0], "exit") == 0)
	// 	exit_builtin(ctx, ast_node->cmd_args);
	else if (ft_strcmp(ast_node->cmd_args[0], ":") == 0)
		ctx->exit_status = EXIT_SUCCESS;
}
