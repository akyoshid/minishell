/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 04:02:48 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/08 12:13:06 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	_handle_fork_error(t_ctx *ctx)
{
	print_error("fork", NULL, NULL, true);
	ctx->exit_status = EXIT_FAILURE;
}

static void	_run_in_child(t_ast *ast_node, char *path, char **envp)
{
	execve(path, ast_node->cmd_args, envp);
	print_error(path, NULL, NULL, true);
	exit(EXIT_NOTEXEC);
}

static void	_run_in_parent(t_ctx *ctx, pid_t pid)
{
	int	status;
	int	signum;

	if (waitpid(pid, &status, 0) == -1)
	{
		restore_std_io(ctx);
		print_error("waitpid", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
	}
	else
	{
		restore_std_io(ctx);
		if (WIFEXITED(status))
			ctx->exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			signum = WTERMSIG(status);
			if (signum == SIGINT)
				ft_dprintf(STDERR_FILENO, "\n");
			else
				ft_dprintf(STDERR_FILENO, "%s\n", ctx->sig_list[signum]);
			ctx->exit_status = 128 + signum;
		}
	}
}

void	exec_external_command(t_ctx *ctx, t_ast *ast_node)
{
	char	*path;
	char	**envp;
	pid_t	pid;

	path = get_path(ctx, ast_node->cmd_args[0]);
	if (path == NULL)
		return ;
	envp = create_envp(ctx);
	pid = fork();
	if (pid == -1)
		_handle_fork_error(ctx);
	else if (pid == 0)
		_run_in_child(ast_node, path, envp);
	else
		_run_in_parent(ctx, pid);
	free(path);
	free_2d_array(envp);
}
