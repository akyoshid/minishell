/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:13:06 by akyoshid          #+#    #+#             */
/*   Updated: 2025/04/04 05:37:37 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	_init_ctx(t_ctx *ctx, char **envp)
{
	init_env_list(envp, ctx);
	ctx->exit_status = EXIT_SUCCESS;
	dup_std_io(ctx);
}

static void	_clear_ctx(t_ctx *ctx)
{
	clear_env_list(&ctx->env_list);
	close_std_io_dup(ctx);
}

int	main(int argc, char **argv, char **envp)
{
	t_ctx	ctx;

	(void)argc;
	(void)argv;
	_init_ctx(&ctx, envp);
	reader_loop(&ctx);
	_clear_ctx(&ctx);
	return (ctx.exit_status);
}
