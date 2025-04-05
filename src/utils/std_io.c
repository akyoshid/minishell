/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 05:19:10 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/04 05:57:16 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	dup_std_io(t_ctx *ctx)
{
	ctx->std_io_dup[STDIN_FILENO] = dup(STDIN_FILENO);
	if (ctx->std_io_dup[STDIN_FILENO] == -1)
	{
		print_error("dup", NULL, NULL, true);
		exit(EXIT_FAILURE);
	}
	ctx->std_io_dup[STDOUT_FILENO] = dup(STDOUT_FILENO);
	if (ctx->std_io_dup[STDOUT_FILENO] == -1)
	{
		print_error("dup", NULL, NULL, true);
		exit(EXIT_FAILURE);
	}
	ctx->std_io_dup[STDERR_FILENO] = dup(STDERR_FILENO);
	if (ctx->std_io_dup[STDERR_FILENO] == -1)
	{
		print_error("dup", NULL, NULL, true);
		exit(EXIT_FAILURE);
	}
}

void	close_std_io_dup(t_ctx *ctx)
{
	close(ctx->std_io_dup[STDIN_FILENO]);
	close(ctx->std_io_dup[STDOUT_FILENO]);
	close(ctx->std_io_dup[STDERR_FILENO]);
}

// On success, restore_std_io() returns 0.
// On error, it returns -1.
int	restore_std_io(t_ctx *ctx)
{
	if (dup2(ctx->std_io_dup[STDIN_FILENO], STDIN_FILENO) == -1)
	{
		print_error("dup2", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
		return (-1);
	}
	else if (dup2(ctx->std_io_dup[STDOUT_FILENO], STDOUT_FILENO) == -1)
	{
		print_error("dup2", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
		return (-1);
	}
	else if (dup2(ctx->std_io_dup[STDERR_FILENO], STDERR_FILENO) == -1)
	{
		print_error("dup2", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
		return (-1);
	}
	return (0);
}
