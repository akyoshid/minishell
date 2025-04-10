/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_std_io.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 05:19:10 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/10 17:17:16 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_std_io_dup(t_ctx *ctx)
{
	ctx->std_io_dup[STDIN_FILENO] = -1;
	ctx->std_io_dup[STDOUT_FILENO] = -1;
	ctx->std_io_dup[STDERR_FILENO] = -1;
}

void	close_std_io_dup(t_ctx *ctx)
{
	w_close(ctx->std_io_dup[STDIN_FILENO]);
	w_close(ctx->std_io_dup[STDOUT_FILENO]);
	w_close(ctx->std_io_dup[STDERR_FILENO]);
	init_std_io_dup(ctx);
}

void	dup_std_io(t_ctx *ctx)
{
	close_std_io_dup(ctx);
	ctx->std_io_dup[STDIN_FILENO] = dup(STDIN_FILENO);
	if (ctx->std_io_dup[STDIN_FILENO] == -1)
	{
		print_error("dup", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
	}
	ctx->std_io_dup[STDOUT_FILENO] = dup(STDOUT_FILENO);
	if (ctx->std_io_dup[STDOUT_FILENO] == -1)
	{
		print_error("dup", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
	}
	ctx->std_io_dup[STDERR_FILENO] = dup(STDERR_FILENO);
	if (ctx->std_io_dup[STDERR_FILENO] == -1)
	{
		print_error("dup", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
	}
}

void	restore_std_io(t_ctx *ctx)
{
	if (w_dup2(ctx->std_io_dup[STDIN_FILENO], STDIN_FILENO) == -1)
	{
		print_error("dup2", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
	}
	if (w_dup2(ctx->std_io_dup[STDOUT_FILENO], STDOUT_FILENO) == -1)
	{
		print_error("dup2", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
	}
	if (w_dup2(ctx->std_io_dup[STDERR_FILENO], STDERR_FILENO) == -1)
	{
		print_error("dup2", NULL, NULL, true);
		ctx->exit_status = EXIT_FAILURE;
	}
	close_std_io_dup(ctx);
}
