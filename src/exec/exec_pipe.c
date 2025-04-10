/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:45:00 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/10 08:40:53 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// subshell is also counted as one command.
static int	_count_commands_in_pipe(t_ast *ast_node)
{
	int		count;

	count = 1;
	while (ast_node->type == AST_PIPE)
	{
		count++;
		ast_node = ast_node->left;
	}
	return (count);
}

static t_ast	**_create_cmd_list(t_ast *ast_node, int cmd_count)
{
	t_ast	**cmd_list;
	int		i;

	cmd_list = (t_ast **)xmalloc(cmd_count * sizeof(t_ast *));
	i = 0;
	while (i < cmd_count)
	{
		if (i < cmd_count - 1)
			cmd_list[cmd_count - (i + 1)] = ast_node->right;
		else
			cmd_list[cmd_count - (i + 1)] = ast_node->left;
		if (i < cmd_count - 2)
			ast_node = ast_node->left;
		i++;
	}
	return (cmd_list);
}

// On success, it returns 0.
// On error, it returns -1.
static int	_exec_commands_in_pipe(
	t_ctx *ctx, t_ast **cmd_list, int *cmd_count_p, pid_t *cmd_pid_list)
{
	int				i;
	t_pipe_fd_set	pipe_fd_set;
	int				pipe_fd[2];

	i = 0;
	init_pipe_fd_set(&pipe_fd_set);
	while (i < *cmd_count_p)
	{
		if (i < *cmd_count_p - 1)
		{
			if (pipe(pipe_fd) == -1)
				return (print_error("pipe", NULL, NULL, true),
					close_pipe_fd_set(&pipe_fd_set), *cmd_count_p = i, -1);
			cmd_pid_list[i] = exec_command_in_pipe(ctx,
					cmd_list[i], update_pipe_fd_set(&pipe_fd_set, pipe_fd));
		}
		else
			cmd_pid_list[i] = exec_command_in_pipe(ctx,
					cmd_list[i], update_pipe_fd_set(&pipe_fd_set, NULL));
		if (cmd_pid_list[i] == -1)
			return (*cmd_count_p = i, -1);
		i++;
	}
	return (close_pipe_fd(pipe_fd_set.current_read), 0);
}

static void	_wait_commands_in_pipe(
	t_ctx *ctx, int cmd_count, pid_t *cmd_pid_list)
{
	int	i;

	i = 0;
	while (i < cmd_count)
	{
		if (i == cmd_count - 1)
			wait_child(ctx, cmd_pid_list[i]);
		else if (waitpid(cmd_pid_list[i], NULL, 0) == -1)
			print_error("waitpid", NULL, NULL, true);
		i++;
	}
}

void	exec_pipe(t_ctx *ctx, t_ast *ast_node)
{
	int		cmd_count;
	t_ast	**cmd_list;
	pid_t	*cmd_pid_list;

	cmd_count = _count_commands_in_pipe(ast_node);
	cmd_list = _create_cmd_list(ast_node, cmd_count);
	cmd_pid_list = (pid_t *)xmalloc(sizeof(pid_t) * cmd_count);
	dup_std_io(ctx);
	if (_exec_commands_in_pipe(ctx, cmd_list, &cmd_count, cmd_pid_list) == -1)
	{
		_wait_commands_in_pipe(ctx, cmd_count, cmd_pid_list);
		ctx->exit_status = EXIT_FAILURE;
	}
	else
		_wait_commands_in_pipe(ctx, cmd_count, cmd_pid_list);
	restore_std_io(ctx);
	free(cmd_list);
	free(cmd_pid_list);
}
