/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:45:58 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/10 18:50:00 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// AND: Execute the right side only if the left side succeeds (0).
// OR: Execute the right side only if the left side fails (non-0).
void	exec_and_or(t_ctx *ctx, t_ast *ast_node)
{
	exec_ast(ctx, ast_node->left);
	if (ast_node->type == AST_AND)
	{
		if (ctx->exit_status == EXIT_SUCCESS)
			exec_ast(ctx, ast_node->right);
	}
	else if (ast_node->type == AST_OR)
	{
		if (ctx->exit_status != EXIT_SUCCESS)
			exec_ast(ctx, ast_node->right);
	}
}
