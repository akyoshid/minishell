/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_in_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:48:31 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/11 08:13:23 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_handle_fork_error_in_pipe(t_pipe_fd_set *pipe_fd_set)
{
	print_error("fork", NULL, NULL, true);
	close_pipe_fd_set(pipe_fd_set);
}

static void	_run_in_child_in_pipe(
	t_ctx *ctx, t_ast *ast_node, t_pipe_fd_set *pipe_fd_set)
{
	if (setup_pipe(pipe_fd_set) == -1)
		exit(EXIT_FAILURE);
	if (setup_redir(ctx, ast_node->redir_list) == -1)
		exit(EXIT_FAILURE);
	if (ast_node->type == AST_COMMAND)
	{
		if (ast_node->cmd_args == NULL)
			exit(EXIT_SUCCESS);
		if (check_cmd_is_builtin(ast_node->cmd_args[0]) == true)
		{
			exec_builtin_command(ctx, ast_node);
			exit(ctx->exit_status);
		}
		else
			exec_external_command_in_pipe(ctx, ast_node);
	}
	else
	{
		if (ast_node->subshell_ast == NULL)
			exit(EXIT_SUCCESS);
		exec_ast(ctx, ast_node->subshell_ast);
		exit(ctx->exit_status);
	}
}

// If fork() succeeds, it returns the pid of the child process.
// If fork() fails, it returns -1.
// The type of ast_node passed to this function
//  is either AST_COMMAND or AST_SUBSHELL.
pid_t	exec_command_in_pipe(
	t_ctx *ctx, t_ast *ast_node, t_pipe_fd_set *pipe_fd_set)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		_handle_fork_error_in_pipe(pipe_fd_set);
		return (-1);
	}
	if (pid == 0)
		_run_in_child_in_pipe(ctx, ast_node, pipe_fd_set);
	return (pid);
}
