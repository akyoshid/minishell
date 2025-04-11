/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 08:41:04 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/11 09:41:11 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	wait_child(t_ctx *ctx, pid_t pid)
{
	int	status;
	int	signum;

	if (waitpid(pid, &status, 0) == -1)
	{
		handle_signal(ctx);
		print_error("waitpid", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
	}
	else
	{
		handle_signal(ctx);
		if (WIFEXITED(status))
			ctx->exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			signum = WTERMSIG(status);
			ctx->exit_status = 128 + signum;
		}
	}
}
