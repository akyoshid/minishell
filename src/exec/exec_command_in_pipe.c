/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_in_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:48:31 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/10 08:51:02 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_handle_fork_error(t_pipe_fd_set *pipe_fd_set)
{
	print_error("fork", NULL, NULL, true);
	close_pipe_fd_set(pipe_fd_set);
}

// On success, it returns 0.
// On error, it returns -1.
static int	_setup_pipe(t_pipe_fd_set *pipe_fd_set)
{
	if (dup2(pipe_fd_set->current_read, STDIN_FILENO) == -1)
	{
		print_error("dup2", NULL, NULL, true);
		close_pipe_fd_set(pipe_fd_set);
		return (-1);
	}
	if (dup2(pipe_fd_set->current_write, STDOUT_FILENO) == -1)
	{
		print_error("dup2", NULL, NULL, true);
		close_pipe_fd_set(pipe_fd_set);
		return (-1);
	}
	close_pipe_fd_set(pipe_fd_set);
	return (0);
}

static void	_run_in_child(
	t_ctx *ctx, t_ast *ast_node, t_pipe_fd_set *pipe_fd_set)
{
	if (_setup_pipe(pipe_fd_set) == -1)
		exit(EXIT_FAILURE);
	if (setup_redir(ctx, ast_node->redir_list) == -1)
		exit(EXIT_FAILURE);
	if (ast_node->type == AST_COMMAND)
	{
		if (ast_node->cmd_args == NULL)
			exit(EXIT_SUCCESS);
		if (check_cmd_is_builtin(ast_node->cmd_args[0]))
		{
			exec_builtin_command(ctx, ast_node);
			exit(ctx->exit_status);
		}
		else
			exec_external_command_in_pipe(ctx, ast_node);
	}
	// else
	// {
	// 	if (ast_node->subshell_ast == NULL)
	// 		exit(EXIT_SUCCESS);
	// 	exec_subshell(ctx, ast_node);
	// }
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
		_handle_fork_error(pipe_fd_set);
		return (-1);
	}
	if (pid == 0)
		_run_in_child(ctx, ast_node, pipe_fd_set);
	return (pid);
}
