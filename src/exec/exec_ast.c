/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:04:24 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/08 03:52:07 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exec_ast(t_ctx *ctx, t_ast *ast_top_node)
{
	if (ast_top_node == NULL)
	{
		ctx->exit_status = EXIT_USAGE;
		return ;
	}
	// else if (ast_top_node->type == AST_AND || ast_top_node->type == AST_OR)
	// 	exec_and_or(ctx, ast_top_node);
	// else if (ast_top_node->type == AST_PIPE)
	// 	exec_pipe(ctx, ast_top_node);
	else if (ast_top_node->type == AST_COMMAND)
		exec_command(ctx, ast_top_node);
	// else if (ast_top_node->type == AST_SUBSHELL)
	// 	exec_subshell(ctx, ast_top_node);
	else
	{
		ctx->exit_status = EXIT_USAGE;
		return ;
	}
}
