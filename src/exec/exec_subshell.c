/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:15:01 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 15:09:45 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_handle_fork_error_in_subshell(t_ctx *ctx)
{
	print_error("fork", NULL, NULL, true);
	ctx->exit_status = EXIT_FAILURE;
}

static void	_run_in_child_in_subshell(t_ctx *ctx, t_ast *ast_node)
{
	if (setup_redir(ctx, ast_node->redir_list) == -1)
		exit(EXIT_FAILURE);
	if (ast_node->subshell_ast == NULL)
		exit(EXIT_SUCCESS);
	exec_ast(ctx, ast_node->subshell_ast);
	exit(ctx->exit_status);
}

void	exec_subshell(t_ctx *ctx, t_ast *ast_node)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		_handle_fork_error_in_subshell(ctx);
	else if (pid == 0)
		_run_in_child_in_subshell(ctx, ast_node);
	else
		wait_child(ctx, pid);
}
