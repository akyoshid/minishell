/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 08:41:04 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/13 01:25:33 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	wait_child(t_ctx *ctx, pid_t last_pid)
{
	int	ret;
	int	status;
	int	signum;

	ret = waitpid(-1, &status, 0);
	if (ret == -1)
	{
		print_error("waitpid", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
	}
	else if (ret == last_pid)
	{
		if (WIFEXITED(status))
			ctx->exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			signum = WTERMSIG(status);
			ctx->exit_status = 128 + signum;
			if (ctx->exit_status > 128 && ctx->exit_status != 128 + SIGINT)
				ft_dprintf(STDERR_FILENO, "%s",
					ctx->sig_list[ctx->exit_status - 128]);
			if (ctx->exit_status > 128)
				ft_dprintf(STDERR_FILENO, "\n");
		}
	}
}
